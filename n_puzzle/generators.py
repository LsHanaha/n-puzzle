import random
from typing import List


def get_next_direction(n: int,
                       puzzle: List[int],
                       i: int,
                       current_direction: int):
    if abs(current_direction) == 1:
        if (i // n == (i + current_direction) // n
                and puzzle[i + current_direction] is None):
            return current_direction
        else:
            return n * current_direction
    else:
        if (0 < i + current_direction < n * n
                and puzzle[i + current_direction] is None):
            return current_direction
        else:
            return current_direction // -n


def generate_goal(n: int, mode: str) -> List[int]:
    if mode == "snail":
        return generate_snail(n)
    goal = list(range(1, n ** 2)) + [0]
    if mode == "random":
        random.shuffle(goal)
    return goal


def generate_snail(n: int) -> List[int]:
    goal = [None for _ in range(n * n)]
    direction = 1  # 1 for right, -1 for left, n for down, -n for up
    i = -1
    for tile in range(1, n * n):
        i += direction
        goal[i] = tile
        direction = get_next_direction(n, goal, i, direction)
    goal[i + direction] = 0
    return goal
