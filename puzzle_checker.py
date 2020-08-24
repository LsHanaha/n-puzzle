
from math import sqrt
from typing import List, Dict


def count_inversions(puzzle: List[int], goal: List[int], side_len: int) -> int:

    res = 0
    size = side_len * side_len
    for i in range(size - 1):
        for j in range(i + 1, size):
                pi = puzzle[i]
                pj = puzzle[j]
                if goal.index(pi) > goal.index(pj):
                    res += 1
    return res


def get_manhattan_score(puzzle: List[int], goal: List[int], side_len: int) -> int:

    puzzle_row = puzzle.index(0) // side_len
    puzzle_column = puzzle.index(0) % side_len
    goal_row = goal.index(0) // side_len
    goal_column = goal.index(0) % side_len
    dist = abs(puzzle_row - goal_row) + abs(puzzle_column - goal_column)
    return dist



def is_solvable(puzzle: List[int], goal: List[int], side_len: int) -> bool:

    inversions = count_inversions(puzzle, goal, side_len)
    dist = get_manhattan_score(puzzle, goal, side_len)
    if not (dist + inversions) % 2:
        return True
    return False
    # return not (dist + inversions) % 2 ?
