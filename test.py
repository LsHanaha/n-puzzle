from n_puzzle.a_star import a_star
from n_puzzle.puzzle import Puzzle
from n_puzzle import heuristics


def test_can_reach_finish(puzzle):
    Puzzle.set_side_len(int(len(puzzle) ** 0.5))
    puzzle = Puzzle(puzzle, g=0, h=0, parent=None)
    assert a_star(puzzle, heuristics.manhattan) == sorted(puzzle)


test_can_reach_finish([4, 0, 8, 2, 10, 12, 5, 7, 13, 9, 3, 14, 15, 11, 6, 1])
