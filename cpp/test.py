import cpp_backend
import sys
import argparse
from math import sqrt

parser = argparse.ArgumentParser()
parser.add_argument("map", type=int, nargs="*")
parser.add_argument("--euristic", type=str, default="phased_manhattan")
args = parser.parse_args()

result = cpp_backend.solve(int(sqrt(len(args.map))), args.map, args.euristic)
print(result)
