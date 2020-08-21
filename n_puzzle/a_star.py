from n_puzzle.puzzle import Puzzle
from n_puzzle.get_neighbours import get_neighbours

import heapq
from typing import Callable, List


def a_star(current_config: Puzzle, heuristic: Callable):
    visited = {hash(current_config): current_config}
    priority_q = []
    heapq.heapify(priority_q)
    current_config.h = heuristic(current_config)
    if not current_config.h:
        return current_config

    while heuristic(current_config):
        for neighbour in get_neighbours(current_config):

            permutation_id = hash(neighbour)
            if permutation_id not in visited:
                neighbour.h = heuristic(neighbour)

                if not neighbour.h:
                    return neighbour

                heapq.heappush(priority_q, neighbour)
            elif current_config.g + 1 < visited[permutation_id].g:
                visited[permutation_id].g = current_config.g + 1
                visited[permutation_id].parent = current_config

        current_config = heapq.heappop(priority_q)
        visited[hash(current_config)] = current_config
