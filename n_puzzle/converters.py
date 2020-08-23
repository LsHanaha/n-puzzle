from typing import List



def converter(puzzle: List[int]):
    res = []
    size = len(puzzle) - 1
    for val in puzzle:
        if val == 0:
            res.append(size)
            continue
        res.append(val - 1)
    return res


def convert_to_indexes(puzzle: list, side_len: int):
    res = {}
    for i, val in enumerate(puzzle):
        res[val] = (i // side_len, i % side_len, i)
    return res
