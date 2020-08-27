from n_puzzle.generators import generate_goal
from n_puzzle.handle_result import HandleResult
from n_puzzle.solve_puzzle import Solver
from puzzle_checker import is_solvable

import argparse
import sys
from math import sqrt
from typing import List, Tuple


def check_puzzle(size: int, puzzle: List[int]) -> None:
    if len(puzzle) != size * size:
        print(f"Map size mismatch: {size * size}"
              f" and {len(puzzle)} elements", file=sys.stderr)
        exit(1)
    if not sorted(puzzle) == list(range(len(puzzle))):
        print("Puzzle must consist of numbers from 0 to N-1", file=sys.stderr)
        exit(1)


def parse_args() -> argparse.Namespace:

    def wrap_file(file_like) -> str:
        if not file_like:
            return sys.stdin.read() if not sys.stdin.isatty() else None
        if not sys.stdin.isatty():
            print("Cannot pass file AND stdin.", file=sys.stderr)
            sys.stdin.read()
            exit(1)
        with open(file_like) as f:
            return f.read()

    parser = argparse.ArgumentParser(description="An n-puzzle solver, accepts"
                                     " input as arguments, from file or from"
                                     " stdin. See -h for details.")

    parser.add_argument("-q", action="store_true", help="Quiet mode.")

    parser.add_argument("--cpp", action="store_true",
                        help="Activate c++ backend.")
    parser.add_argument("--he", "--heuristic", default="manhattan",
                        choices=["manhattan", "n_misplaced", "uniform",
                                 "greedy_manh", "phased_manh", "rowwise_manh"],
                        help="Select a heuristic, defaults to 'manhattan'.")

    parser.add_argument("--file", type=wrap_file,
                        default="",
                        help="A file to read the puzzle from."
                             " Defaults to stdin.")
    parser.add_argument("-p", "--puzzle", type=int, nargs="+",
                        help="The puzzle to solve."
                             " Incompatible with file input.")
    parser.add_argument("-g", "--goal", type=int, nargs="+",
                        help="The goal for the solver."
                             " If set, and the input is from file,"
                             " the file must not define a goal.")
    parser.add_argument("-m", "--mode", choices=("classic", "snail", "random"),
                        default="snail",
                        help="The version of goal to generate if it's missing,"
                             " defaults to 'snail'. Ignored if goal's passed.")
    args = parser.parse_args()
    return args


def read_from_file(args: argparse.Namespace) -> Tuple[int, List[int], List[int]]:  # noqa E501
    """
    Reads size, puzzle and goal from file, be it stdin or an ordinary file.
    Checks that there are values in file and that all the values are integers.
    Does not perform other checks.
    """
    if args.file is None:
        return None, None, None

    data = []
    for line in args.file.splitlines():
        read_limit = line.find("#")
        if read_limit == -1:
            read_limit = len(line)
        data.extend(line[:read_limit].split())

    try:
        data = [int(elem) for elem in data]
    except ValueError:
        print("Invalid format: tiles must be integers.", file=sys.stderr)
        exit(1)

    try:
        size = data[0]
        puzzle = data[1: size * size + 1]
        goal = data[size * size + 1:]
    except IndexError:
        print("Invalid format: missing values.", file=sys.stderr)
        exit(1)

    return size, puzzle, goal


def read_puzzle(args: argparse.Namespace) -> Tuple[int, List[int], List[int]]:
    """Reads the puzzle from various sources, checks for errors."""
    size, puzzle, goal = read_from_file(args)
    if args.puzzle:
        if puzzle:
            print("Cannot define puzzle from file and from command-line"
                  " arguments, choose one.", file=sys.stderr)
            exit(1)
        puzzle = args.puzzle
    if args.goal:
        if goal:
            print("Cannot define goal from file and from command-line"
                  " arguments, choose one.", file=sys.stderr)
            exit(1)
        goal = args.goal
    if size is None:
        size = int(sqrt(len(puzzle)))
    if not goal:
        goal = generate_goal(size, args.mode)
    check_puzzle(size, puzzle)
    check_puzzle(size, goal)
    return size, puzzle, goal


def show_task_info(puzzle: List[int], goal: List[int], size: int) -> None:
    print('Incoming puzzle: ')
    HandleResult(puzzle, size).print_puzzle(puzzle)
    print('Goal target: ')
    HandleResult(goal, size).print_puzzle(goal)


if __name__ == "__main__":
    args = parse_args()
    size, puzzle, goal = read_puzzle(args)
    show_task_info(puzzle, goal, size)
    if not is_solvable(puzzle, goal, size):
        print("The puzzle has no solution.")
        exit()
    result = Solver(args.he, args.cpp).solve_puzzle(size, puzzle, goal)
    HandleResult(puzzle, size).show_result(result, args.q)
