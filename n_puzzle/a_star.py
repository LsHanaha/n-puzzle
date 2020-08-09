from Puzzle import Puzzle
from get_neighbours import get_neighbours

import heapq
from typing import Callable, List


def a_star(current_config: Puzzle, euristic: Callable[[List[int]], int]):
    visited = {hash(current_config): current_config}
    priority_q = []
    heapq.heapify(priority_q)

    while euristic(current_config):
        for neighbour in get_neighbours(current_config):

            permutation_id = hash(neighbour)
            if permutation_id not in visited:
                neighbour.h = euristic(neighbour)
                heapq.heappush(priority_q, neighbour)
            elif current_config.g + 1 < visited[permutation_id].g:
                visited[permutation_id].g = current_config.g + 1
                visited[permutation_id].parent = current_config

        current_config = heapq.heappop(priority_q)
        visited[hash(current_config)] = current_config

    return current_config

import euristics
puzzle = [11, 10, 15,  2,  5,  9, 13,  6,  4,  3,  7, 12,  1,  8, 0, 14]
Puzzle.set_side_len(int(len(puzzle) ** 0.5))
puzzle = Puzzle(puzzle, g=0, h=0, parent=None)
goal = sorted(puzzle)
assert a_star(puzzle, euristics.manhattan) == goal

