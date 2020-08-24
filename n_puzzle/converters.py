from typing import List, Tuple


def converter(puzzle: List[int]) -> List[int]:
    res = []
    size = len(puzzle) - 1
    for val in puzzle:
        if val == 0:
            res.append(size)
            continue
        res.append(val - 1)
    return res


def convert_to_indexes(puzzle: list, side_len: int) -> List[Tuple[int, int]]:
    # return list - values from goal is placed in order [0..value], each element in
    # list a tuple. Example [1, 2, 0, 3] -> [(yi, xi) # это какбы ноль, (0, 0), (0, 1), (1, 1)]
    res = [tuple() for _ in range(side_len * side_len)]
    for i, val in enumerate(puzzle):
        res[val] = (i // side_len, i % side_len)
    print(res)
    return res
