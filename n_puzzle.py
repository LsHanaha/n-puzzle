import argparse
import sys

if __name__ == "__main__":

    parser = argparse.ArgumentParser()
    parser.add_argument("size", type=int, default=None, help="Size of the puzzle's side. Must be >3.")
    parser.add_argument("--puzzle", type=int, nargs='+', default=None, help="Size of the puzzle's side. Must be >3.")
    parser.add_argument("-s", "--solvable", action="store_true", default=False,
                        help="Forces generation of a solvable puzzle. Overrides -u.")
    parser.add_argument("-u", "--unsolvable", action="store_true", default=False,
                        help="Forces generation of an unsolvable puzzle")
    parser.add_argument("-f", "--file", type=str, default=False,
                        help="Forces generation of an unsolvable puzzle")
    parser.add_argument("-cli", action="store_true", default=False,
                        help="Forces generation of an unsolvable puzzle")

    args = parser.parse_args()

    if args.cli:
        print(str(sys.__stdin__))
        for line in sys.stdin:
            print(f"line = '{line}'")

    print(args)
