from math import sqrt
import random
import sys


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
    print(zero_id + res)
    return (zero_id + res) % 2 == 0


def generator(size: int, solvable: bool):
    puzzle = list(range(size * size))
    random.shuffle(puzzle)
    while (solvable != is_solvable(puzzle)):
        random.shuffle(puzzle)
    print(f"This puzzle is {'' if solvable else 'un'}solvable")
    print(*puzzle, sep=", ")


if __name__ == "__main__":
    size = int(sys.argv[1])
    assert sys.argv[2] == "solvable" or sys.argv[2] == "unsolvable"
    solvable = sys.argv[2] == "solvable"
    generator(size, solvable)
