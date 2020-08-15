import sys
import argparse


if __name__ == "__main__":
    print(sys.argv)
    parser = argparse.ArgumentParser()
    parser.add_argument("size", type=int, help="Size of the puzzle's side. Must be >3.")
    parser.add_argument("-p", "puzzle", type=int, nargs='+',  action="store_true", default=None, help="Size of the puzzle's side. Must be >3.")
    parser.add_argument("-s", "--solvable", action="store_true", default=False,
                        help="Forces generation of a solvable puzzle. Overrides -u.")
    parser.add_argument("-u", "--unsolvable", action="store_true", default=False,
                        help="Forces generation of an unsolvable puzzle")


    args = parser.parse_args()
    print(args.puzzle)
