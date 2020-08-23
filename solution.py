import argparse
import sys
from typing import Optional, List, Tuple, Union
from puzzle_checker import is_solvable
from n_puzzle.converters import converter, convert_to_indexes
from n_puzzle.solve_puzzle import Solver


class GetPuzzle:

    def get_puzzle(self, args: argparse.Namespace) -> Tuple[int, List[int]]:
        if args.puzzle:
            size, puzzle = self._read_args(args)
        elif args.file:
            size, puzzle = self._read_file(args)
        else:
            size, puzzle = self._read_pipe()
        
        goal = self.get_goal(args, size)
        return size, puzzle, goal

    def _read_pipe(self) -> Tuple[int, List[int]]:
        data = []
        for row in sys.__stdin__:
            data.append(row)
        print("pipe = ", data)
        if not data:
            raise BrokenPipeError("Found nothing in Pipe")
        size, puzzle = self._read_puzzle(data)
        return size, puzzle

    def _read_file(self, args: argparse.Namespace) -> Tuple[int, List[int]]:
        filename = args.file

        data = []
        with open(filename, encoding="utf-8") as file:
            for row in file:
                data.append(row)
        if not data:
            raise ValueError("Found nothing in file")
        size, puzzle = self._read_puzzle(data)
        return size, puzzle

    def _read_args(self, args: argparse.Namespace) -> Tuple[int, List[int]]:
        size = args.size
        puzzle = args.puzzle
        self._check_symbols(size, puzzle)
        return size, puzzle

    def _read_puzzle(self, raw_puzzle: List[str]) -> Tuple[int, List[int]]:
        data = []
        for row in raw_puzzle:
            if isinstance(row, str) and "#" in row:
                row = row[:row.index('#')]
            if row:
                data.append(row.strip())
        data = [val for val in data if val]
        res = []
        for val in data:
            res.extend(val.split(' '))
        data = res
        if data:
            size = data.pop(0)
            print(data)
            if isinstance(size, str) and size.isdigit():
                size = int(size)
            else:
                raise ValueError("Size have to be integer")

            puzzle = self.__convert_list_to_int(data)
            self._check_symbols(size, puzzle)
            return size, puzzle
        raise ValueError("Where is the integers?")

    def get_goal(self,  args: argparse.Namespace, size: int) -> List[int]:
        goal = args.goal
        if goal:
            self._check_symbols(size, goal, target='goal')
        else:
            goal = self._get_default_goal(size)
        return goal

    @staticmethod
    def __convert_list_to_int(array: List[str]) -> List[int]:
        try:
            res = [int(i) for i in array]
        except ValueError:
            raise ValueError("Only ints allowed in puzzle")
        return res

    @staticmethod
    def _check_symbols(size: int, puzzle: List[Union[int, str]], target: str = 'puzzle') -> None:

        if size is None or not isinstance(size, int):
            raise ValueError("Only int allowed")
        if size < 2:
            raise ValueError("Size value have to be more than 1")

        valid_puzzle = [i for i in range(size * size)]
        if sorted(puzzle) != valid_puzzle:
            raise ValueError(f"This {target} is wrong. Check symbols and it's count. "
                             f"Values in {target} have to be in range [0, size*size - 1]."
                             f" Repeats are unacceptable.")

    @staticmethod
    def _get_default_goal(size: int):
        if size == 2:
            goal = [1, 2, 4, 3]
        elif size == 3:
            goal = [1, 2, 3, 8, 0, 4, 7, 6, 5]
        elif size == 4:
            goal = [1, 2, 3, 4, 12, 13, 14, 5, 11, 0, 15, 6, 10, 9, 8, 7]
        elif size == 5:
            goal = [1, 2, 3, 4, 5, 16, 17, 18, 19, 6, 15, 24, 0, 20, 7, 14, 23, 22, 21, 
            8, 13, 12, 11, 10, 9]
        elif size == 6:
            pass
        else:
            pass
        return goal


class HandleResult:
    def __init__(self, start: List[int], size: int):
        self._start = start
        self._size = size

    def show_result(self, solution: str, quiet: bool):
        print("Solution: ", solution)
        if not quiet:
            print('=' * (self._size * 4))
            print("Start config:")
            self._print_puzzle(self._start)
            step = self._start

            for move in solution:
                print(move)
                step, switch = self._move_empty_square(step, move)
                self._print_puzzle(step, switch)

    def _print_puzzle(self, puzzle: List[int], switch: Optional[int] = None):
        for i, val in enumerate(puzzle):
            if not val:
                print('\033[31m{:2}\033[0m'.format(val), end=" ")
            elif val == switch:
                print('\033[32m{:2}\033[0m'.format(val), end=" ")
            else:
                print("{:2}".format(val), end=" ")
            if (i + 1) % self._size == 0:
                print()
        print('=' * (self._size * 4))

    def _move_empty_square(self, arr: List[int], move: str):
        zero_id = arr.index(0)
        if move == 'u':
            arr[zero_id], arr[zero_id - self._size] = arr[zero_id - self._size], arr[zero_id]
        elif move == 'l':
            arr[zero_id], arr[zero_id - 1] = arr[zero_id - 1], arr[zero_id]
        elif move == 'r':
            arr[zero_id], arr[zero_id + 1] = arr[zero_id + 1], arr[zero_id]
        elif move == 'd':
            arr[zero_id], arr[zero_id + self._size] = arr[zero_id + self._size], arr[zero_id]
        return arr, arr[zero_id]


def activate_tty():
    parser = argparse.ArgumentParser(description="Add some arguments or use pipe. It's up to you")
    parser.add_argument('-s', "--size", type = int, 
                        help="Length of your puzzle side")
    parser.add_argument("-p", "--puzzle", type=int, nargs='+',
                        help="Puzzle himself")
    parser.add_argument('-g', "--goal", type = int, nargs='+', default=None,
                        help="It's goal configuration of puzzle. Snail as default")
    parser.add_argument("-f", "--file", type=str, default=False,
                        help="Read puzzle from file")
    parser.add_argument("-q", default=False, action="store_true",
                        help="Quiet mode.")
    parser.add_argument("-v", default=False, action="store_true",
                        help="Activate advanced output information.")
    parser.add_argument("--cpp", default=False, action="store_true",
                        help="Activate c++ backend.")
    parser.add_argument("--he", type=str, default='manh', choices=['manh', 'heim', 'super',
                                                                   'best', 'greedy', 'yolo'],
                        help="Choose heuristic for solution. Default is simple manhattan. "
                             "Available:\n manh - manhattan(default);\nheim - Haimling;\n"
                             "super - upgraded manhattan;\nbest - the best manhattan;\n"
                             "greedy - activate greedy mode;\nyolo - fuck mandatory, cause yolo!;")

    args = parser.parse_args()
    return args


def read_puzzle(args: argparse.Namespace) -> Tuple[int, List[int], List[int]]:
    error = False

    try:
        size, puzzle, goal = GetPuzzle().get_puzzle(args)
    except (ValueError, BrokenPipeError) as e:
        print(e, " \nThis is the end.")
        error = True
    finally:
        if not sys.stdin.isatty():
            sys.stdin.read()

    if error:
        exit()
    return size, puzzle, goal


def main():

    args = activate_tty()
    size, puzzle, goal = read_puzzle(args)
    # TODO remove
    HandleResult(puzzle, size)._print_puzzle(puzzle)
    if not is_solvable(puzzle, goal, size):
        print(f"Puzzle '{puzzle}' have no solution."
              f"\nThis is the end")
        exit()
    result = Solver(args.he, args.cpp).solve_puzzle(size, puzzle, goal)
    HandleResult(puzzle, size).show_result(result, args.q or args.v)


if __name__ == "__main__":
    main()
