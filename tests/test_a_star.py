import pytest
from n_puzzle.a_star import a_star
from n_puzzle.Puzzle import Puzzle
from n_puzzle import euristics


@pytest.mark.parametrize("puzzle", [
    [4, 3, 9, 14, 2, 13, 7, 11, 5, 0, 6, 12, 15, 8, 1, 10]
])
def test_can_reach_finish(puzzle):
    Puzzle.set_side_len(int(len(puzzle) ** 0.5))
    puzzle = Puzzle(puzzle, g=0, h=0, parent=None)
    goal = sorted(puzzle)
    assert a_star(puzzle, euristics.hemming) == goal
    assert a_star(puzzle, euristics.manhattan) == goal
