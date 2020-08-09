import pytest
from n_puzzle.Puzzle import Puzzle
from n_puzzle import euristics


@pytest.mark.parametrize("puzzle,result", [
    [[1, 2, 3, 4, 5, 6, 7, 8, 0], 0],
    [[0, 3, 8, 7, 6, 5, 2, 4, 1], 9],
    [[1, 2, 5, 4, 3, 7, 6, 8, 0], 4]
])
def test_hemming(puzzle, result):
    Puzzle.set_side_len(int(len(puzzle) ** 0.5))
    puzzle = Puzzle(puzzle, g=0, h=0, parent=None)
    assert euristics.hemming(puzzle) == result


@pytest.mark.parametrize("puzzle,result", [
    [[1, 2, 3, 4, 5, 6, 7, 8, 0], 0],
    [[1, 2, 3, 0, 8, 7, 5, 6, 4], 14],
    [[0, 8, 7, 6, 5, 4, 3, 2, 1], 24]
])
def test_manhattan(puzzle, result):
    Puzzle.set_side_len(int(len(puzzle) ** 0.5))
    puzzle = Puzzle(puzzle, g=0, h=0, parent=None)
    assert euristics.manhattan(puzzle) == result
