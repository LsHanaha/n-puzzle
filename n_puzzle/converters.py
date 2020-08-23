from typing import List, Tuple, Dict



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
    res = {}
    for i, val in enumerate(puzzle):
        res[val] = (i // side_len, i % side_len)
    
    res_list = []
    for i in range(side_len * side_len):
        res_list.append(res[i])
    return res
