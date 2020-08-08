import sys
import argparse


if __name__ == "__main__":
    print(sys.argv)
    parser = argparse.ArgumentParser()
    parser.add_argument("map", type=int, nargs='+', help="Size of the puzzle's side. Must be >3.")
    parser.add_argument("-s", "--solvable", action="store_true", default=False,
                        help="Forces generation of a solvable puzzle. Overrides -u.")
    parser.add_argument("-u", "--unsolvable", action="store_true", default=False,
                        help="Forces generation of an unsolvable puzzle")
    parser.add_argument("-i", "--iterations", type=int, default=10000, help="Number of passes")

    args = parser.parse_args()
    print(args)
