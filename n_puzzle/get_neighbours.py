from typing import List
from Puzzle import Puzzle


def _cook_new_map(current: Puzzle, zero_id:int, new_id:int) -> Puzzle:

    new_map = current.copy()
    new_map[zero_id], new_map[new_id] = new_map[new_id], new_map[zero_id]

    return Puzzle(list(new_map), g=current.g + 1, h=None, parent=current)


def get_neighbours(current: Puzzle) -> List[Puzzle]:
    """
    top - left - right - bottom
    :param current:
    :return:
    """
    side_len = current.side_len
    result = []
    zero_id = current.index(len(current) - 1)

    if zero_id - side_len >= 0:
        result.append(_cook_new_map(current, zero_id, zero_id - side_len))
    if zero_id % side_len - 1 >= 0:
        result.append(_cook_new_map(current, zero_id, zero_id - 1))
    if zero_id % side_len + 1 < side_len:
        result.append(_cook_new_map(current, zero_id, zero_id + 1))
    if zero_id + side_len < len(current):
        result.append(_cook_new_map(current, zero_id, zero_id + side_len))

    return result
