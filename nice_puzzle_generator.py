from math import sqrt
import random
import sys


# def get_empty_tile_moves(puzzle: list):
#     side_len = int(sqrt(len(puzzle)))
#     zero_id = puzzle.index(len(puzzle) - 1)
#     current_x = zero_id // side_len
#     current_y = zero_id % side_len
#     gold_x = (len(puzzle) - 1) // side_len
#     gold_y = (len(puzzle) - 1) % side_len
#     return abs(gold_x - current_x) + abs(gold_y - current_y)


# def is_solvable(puzzle: list):
#     temp_puzzle = puzzle.copy()
#     sorted_puzzle = list(range(len(puzzle)))
#     n_steps = 0
#     for i in range(len(puzzle)):
#         if temp_puzzle[i] != i:
#             n_steps += 1
#             temp_puzzle[temp_puzzle[i]] = temp_puzzle[i]
#             temp_puzzle[i] = i
#             print(temp_puzzle)
#     return (n_steps + get_empty_tile_moves(puzzle)) % 2 == 0

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


15, 12, 7, 5, 0, 14, 10, 1, 11, 4, 9, 6, 8, 2, 3, 13

1, 12, 13, 11, 9, 10, 4, 2, 5, 15, 7, 3, 0, 14, 6, 8

13, 14, 2, 0, 6, 11, 12, 15, 1, 3, 7, 5, 9, 8, 10, 4

4, 6, 8, 1, 7, 14, 13, 5, 10, 11, 2, 9, 0, 3, 15, 12