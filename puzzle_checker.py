
from math import sqrt


def is_solvable(puzzle):
    res = 0

    size = len(puzzle)
    for i in range(size - 1):
        if not puzzle[i]:
            continue
        for j in range(i+1, size):
            if puzzle[j] and puzzle[i] and puzzle[i] > puzzle[j]:
                res += 1
    if size % 2:
        return res % 2 != 0
    zero_id = puzzle.index(0) // sqrt(size) + 1
    return (res + zero_id) % 2 == 0


def converter(puzzle):

    if isinstance(puzzle, str):
        puzzle = [int(i) for i in puzzle]

    res = []
    size = len(puzzle) - 1
    for val in puzzle:
        if val == size:
            res.append(0)
            continue
        res.append(val + 1)
    return res
