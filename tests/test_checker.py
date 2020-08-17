from puzzle_checker import *
import pytest


@pytest.mark.parametrize("puzzle,expectation", [
    [[1, 8, 2, 0, 4, 3, 7, 6, 5], True],
    [[8, 1, 2, 0, 4, 3, 7, 6, 5], False],
    [[1, 2, 3, 4, 5, 6, 7, 8, 0], True],
    [[1, 2, 3, 4, 5, 6, 8, 7, 0], False],
    [[1,0,3,2,4,5,6,7,8], False],
    [[7,0,2,8,5,3,6,4,1], False],
    [[6, 7, 2, 3, 0, 8, 1, 5, 4], True],
    [[5, 2, 3, 1, 8, 4, 7, 6, 0], True],
    [[5, 7, 1, 4, 2, 3, 8, 6, 0], True],
    [[0, 4, 3, 8, 2, 6, 7, 5, 1], True],
    [[3, 4, 0, 6, 8, 1, 5, 7, 2], False],
    [[3, 8, 0, 2, 5, 1, 4, 6, 7], False],
    [[3, 6, 2, 4, 0, 5, 8, 7, 1], True],
    [[8, 7, 1, 6, 2, 3, 5, 4, 0], True],
    [[2, 8, 4, 7, 3, 1, 0, 6, 5], False]
])
def test_three(puzzle, expectation):
    result = is_solvable2(puzzle)
    assert result == expectation


@pytest.mark.parametrize("puzzle,expectation", [
    [[5, 1, 4, 6, 3, 12, 15, 0, 13, 14, 2, 7, 9, 8, 10, 11], False],
    [[10, 1, 3, 8, 5,  2, 14, 15,  9, 13,  7, 11, 12, 0, 4, 6], True],
    [[ 9, 10,  4,  5,  1, 15,  6, 0,14,  8, 13,  2,   7, 3,  12, 11], False],
    # [[15, 0, 13, 2, 6, 11, 10, 7, 3, 5, 1, 12, 4, 14, 9, 8], True],
    [[14, 15, 11, 13, 5, 1, 7, 2, 12, 0, 9, 8, 10, 3, 4, 6], True]



])
def test_four(puzzle, expectation):
    result = is_solvable2(puzzle)
    assert result == expectation

