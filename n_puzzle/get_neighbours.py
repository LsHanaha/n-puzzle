from typing import List
from n_puzzle.puzzle import Puzzle


def _cook_new_map(parent: Puzzle, zero_id: int, new_id: int) -> Puzzle:

    new_map = parent.board.copy()
    new_map[zero_id], new_map[new_id] = new_map[new_id], new_map[zero_id]

    return Puzzle(new_map, g=parent.g + 1, h=None, parent=parent)


def get_neighbours(parent: Puzzle) -> List[Puzzle]:
    """
    top - left - right - bottom
    """
    result = []
    zero_id = parent.board.index(0)

    if zero_id - parent.side_len >= 0:
        new_map = _cook_new_map(parent, zero_id, zero_id - parent.side_len)
        new_map.set_move('u')
        result.append(new_map)
    if zero_id % parent.side_len - 1 >= 0:
        new_map = _cook_new_map(parent, zero_id, zero_id - 1)
        new_map.set_move('l')
        result.append(new_map)
    if zero_id % parent.side_len + 1 < parent.side_len:
        new_map = _cook_new_map(parent, zero_id, zero_id + 1)
        new_map.set_move('r')
        result.append(new_map)
    if zero_id + parent.side_len < parent.puzzle_len:
        new_map = _cook_new_map(parent, zero_id, zero_id + parent.side_len)
        new_map.set_move('d')
        result.append(new_map)

    return result
