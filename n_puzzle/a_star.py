from .Puzzle import Puzzle
from .get_neighbours import get_neighbours

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
