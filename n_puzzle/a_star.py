from n_puzzle.puzzle import Puzzle
from n_puzzle.get_neighbours import get_neighbours
from n_puzzle.errors import BoardError

from heapq import heappop, heappush
from typing import Callable, Optional


def a_star(current: Puzzle, heuristic: Callable) -> Optional[Puzzle]:
    opened = []
    current.h = heuristic(current)
    werty = 9999
    if not current.h:
        return current
    heappush(opened, current)

    closed = {}
    if current in opened:
        print("YEP!")
    print("START heuristics = ", current.h)
    while opened:

        current = heappop(opened)
        current_id = current.hash
        closed[current_id] = current
        for neighbour in get_neighbours(current):
            neighbour_id = neighbour.hash
            neighbour.h = heuristic(neighbour)
            if neighbour.h < werty or neighbour.h <= 5:
                print(neighbour.h)
                werty = neighbour.h
                print(neighbour.board)

            if not neighbour.h:
                return neighbour

            if neighbour_id in closed:
                if neighbour.g >= closed[neighbour_id].g:
                    continue
                closed[neighbour_id].g = current.g + 1
                closed[neighbour_id].parent = current
            if neighbour in opened:
                print("it's in opened")
            if neighbour not in opened:
                heappush(opened, neighbour)
    raise BoardError("SOLUTION DIN't FOUND?!!!")
