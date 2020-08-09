from Puzzle import Puzzle
from get_neighbours import get_neighbours

import heapq
from typing import Callable, List


def a_star(puzzle: Puzzle, euristic: Callable[[List[int]], int]):
    priority_q = heapq()
    visited = set()

    current_configuration = puzzle
    current_g = 0
    while euristic(current_configuration):
        for neighbour in get_neighbours(current_configuration):
            queue_elem = (euristic(neighbour), current_g + 1, neighbour)
            heapq.heappush(priority_q, queue_elem)
        f, current_g, current_configuration = heapq.heappop(priority_q)
        visited.add(hash(current_configuration))
