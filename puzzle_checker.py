
from math import sqrt
from typing import List, Dict



def count_inversions(puzzle, goal, size):
    res = 0
    for i in range(size * size - 1):
        for j in range(i + 1, size * size):            
                vi = puzzle[i]
                vj = puzzle[j]
                if goal.index(vi) > goal.index(vj):
                    res += 1
    return res



def get_manhattan_score(puzzle, goal, side_len):

    puzzle_row = puzzle.index(0) // side_len
    puzzle_column = puzzle.index(0) % side_len
    goal_row = goal.index(0) // side_len
    goal_column = goal.index(0) % side_len
    dist = abs(puzzle_row - goal_row) + abs(puzzle_column - goal_column)
    return dist



def is_solvable(puzzle, goal, side_len):

    size = len(puzzle)
    inversions = count_inversions(puzzle, goal, side_len)
    dist = get_manhattan_score(puzzle, goal, side_len)
    if not (dist + inversions) % 2:
        return True
    return False


# def is_solvable2(puzzle):
#     res = 0

#     size = len(puzzle)
#     for i in range(size - 1):
#         if not puzzle[i]:
#             continue
#         for j in range(i+1, size):
#             if puzzle[j] and puzzle[i] and puzzle[i] > puzzle[j]:
#                 res += 1
#     if size % 2:
#         return res % 2 != 0
#     zero_id = puzzle.index(0) // sqrt(size) + 1
#     return (res + zero_id) % 2 == 0
