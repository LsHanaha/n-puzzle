#!/usr/bin/env python

import sys
import argparse
import random
from math import sqrt


def make_puzzle(s, solvable, iterations):
    def swap_empty(p):
        idx = p.index(0)
        poss = []
        if idx % s > 0:
            poss.append(idx - 1)
        if idx % s < s - 1:
            poss.append(idx + 1)
        if idx / s > 0 and idx - s >= 0:
            poss.append(idx - s)
        if idx / s < s - 1:
            poss.append(idx + s)
        swi = random.choice(poss)
        p[idx] = p[swi]
        p[swi] = 0

    p = make_goal(s)
    for i in range(iterations):
        swap_empty(p)

    if not solvable:
        if p[0] == 0 or p[1] == 0:
            p[-1], p[-2] = p[-2], p[-1]
        else:
            p[0], p[1] = p[1], p[0]

    return p


def make_goal(s):
    ts = s * s
    puzzle = [-1 for i in range(ts)]
    cur = 1
    x = 0
    ix = 1
    y = 0
    iy = 0
    while True:
        puzzle[x + y * s] = cur
        if cur == 0:
            break
        cur += 1
        if x + ix == s or x + ix < 0 or (ix != 0 and puzzle[x + ix + y * s] != -1):
            iy = ix
            ix = 0
        elif y + iy == s or y + iy < 0 or (iy != 0 and puzzle[x + (y + iy) * s] != -1):
            ix = -iy
            iy = 0
        x += ix
        y += iy
        if cur == s * s:
            cur = 0

    return puzzle


def is_solvable(puzzle: list):
    res = 0
    size = len(puzzle)
    for i in range(size - 1):
        if puzzle[i] == size - 1:
            continue
        for j in range(i + 1, size):
            if puzzle[j] == size - 1:
                continue
            if puzzle[i] > puzzle[j]:
                res += 1

    zero_id = int(puzzle.index(size - 1) / int(sqrt(size))) + 1
    # print(zero_id + res)
    return (zero_id + res) % 2 == 0


def convert(puzzle):
    out = puzzle.copy()
    for i in range(len(puzzle)):
        if out[i] == 0:
            out[i] = 15
        else:
            out[i] -= 1
    return out


if __name__ == "__main__":
    parser = argparse.ArgumentParser()

    parser.add_argument("size", type=int, help="Size of the puzzle's side. Must be >3.")
    parser.add_argument("-s", "--solvable", action="store_true", default=False,
                        help="Forces generation of a solvable puzzle. Overrides -u.")
    parser.add_argument("-u", "--unsolvable", action="store_true", default=False,
                        help="Forces generation of an unsolvable puzzle")
    parser.add_argument("-i", "--iterations", type=int, default=10000, help="Number of passes")

    args = parser.parse_args()

    random.seed()

    if args.solvable and args.unsolvable:
        print("Can't be both solvable AND unsolvable, dummy !")
        sys.exit(1)

    if args.size < 3:
        print("Can't generate a puzzle with size lower than 2. It says so in the help. Dummy.")
        sys.exit(1)

    if args.solvable:
        solv = True
    elif args.unsolvable:
        solv = False
    else:
        solv = random.choice([True, False])

    s = args.size

    puzzle = make_puzzle(s, solvable=solv, iterations=args.iterations)
    print(puzzle)
    puzzle = convert(puzzle)
    print(puzzle)
    res = is_solvable(puzzle)
    print("# my check %s" % ("solvable" if res else "unsolvable"))

    w = len(str(s * s))
    print("# This puzzle is %s" % ("solvable" if solv else "unsolvable"))
    print("%d" % s)
    for y in range(s):
        for x in range(s):
            print ("%s" % (str(puzzle[x + y * s]).rjust(w)))
        # print
