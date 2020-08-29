from n_puzzle.puzzle import Puzzle
from n_puzzle.get_neighbours import get_neighbours
from n_puzzle.errors import BoardError

from heapq import heappop, heappush
from typing import Callable, Optional


def a_star(current: Puzzle, heuristic: Callable) -> Optional[Puzzle]:
    opened = []

    current.h = heuristic(current)
    if not current.h:
        print(f"Total states visited: 0")
        print(f"Max states in memory: 0")
        return current
    heappush(opened, current)
    closed = {}

    while opened:
        current = heappop(opened)
        current_id = current.hash
        closed[current_id] = current
        for neighbour in get_neighbours(current):
            neighbour_id = neighbour.hash
            neighbour.h = heuristic(neighbour)

            if not neighbour.h:
                print(f"Total states visited: {len(closed)}")
                print(f"Max states in memory: {len(closed) + len(opened)}")
                return neighbour

            if neighbour_id in closed:
                if neighbour.g >= closed[neighbour_id].g:
                    continue
                closed[neighbour_id].g = current.g + 1
                closed[neighbour_id].parent = current

            if neighbour not in opened:
                heappush(opened, neighbour)
    raise BoardError("SOLUTION DIN't FOUND?!!!")
