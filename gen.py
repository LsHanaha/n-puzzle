import puzzle_checker
from n_puzzle import generators

import argparse
import random
import sys
from typing import List


def decide_solvability(solvable: bool, unsolvable: bool) -> bool:
    """
    Both 'solvable' and 'unsolvable' cannot be set. If the flags are set,
    returns their meaning. If not, randomly decides the output.
    """
    assert not (solvable and unsolvable)
    if solvable or unsolvable:
        return solvable
    return random.random() > 0.5


def generate_puzzle(n: int, goal: List[int], is_solvable: bool) -> List[int]:
    out = list(range(n * n))
    random.shuffle(out)
    while puzzle_checker.is_solvable(out, goal, n) != is_solvable:
        random.shuffle(out)
    return out


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="N-puzzle map generator")
    parser.add_argument("n", type=int,
                        help="The side of the puzzle to generate."
                             " Must be between 2 and 17.")
    parser.add_argument("-s", action="store_true",
                        help="Only generate solvable puzzles")
    parser.add_argument("-u", action="store_true",
                        help="Only generate unsolvable puzzles")
    parser.add_argument("-m", "--mode", choices=("classic", "snail", "random"),
                        default="snail",
                        help="The version of n-puzzle to generate,"
                             " defaults to 'snail'")
    args = parser.parse_args()

    if args.n < 2 or args.n > 17:
        print("N must be in range [2, 17]", file=sys.stderr)
        exit(1)
    if args.s and args.u:
        print("SO DO YOU WANT SOLVABLE OR UNSOLVABLE MAKE UP YOUR MIND"
              " FOR CHRISTS SAKE", file=sys.stderr)
        exit(1)

    goal = generators.generate_goal(args.n, args.mode)
    solvable = decide_solvability(args.s, args.u)
    puzzle = generate_puzzle(args.n, goal, solvable)
    print(f"# This puzzle is {'un' if not solvable else ''}solvable")
    print(args.n)
    print(*puzzle, sep=" ")
    print(*goal, sep=" ")
