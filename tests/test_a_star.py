import pytest
from n_puzzle.a_star import a_star
from n_puzzle.Puzzle import Puzzle
from n_puzzle import euristics


@pytest.mark.parametrize("puzzle", [
    [3, 8, 1, 7, 0, 6, 4, 5, 2]
])
def test_can_reach_finish(puzzle):
    Puzzle.set_side_len(int(len(puzzle) ** 0.5))
    puzzle = Puzzle(puzzle, g=0, h=0, parent=None)
    goal = sorted(puzzle)
    goal = goal[1:] + goal[:1]
    assert a_star(puzzle, euristics.hemming) == goal
    assert a_star(puzzle, euristics.manhattan) == goal
