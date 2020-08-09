import cProfile
from n_puzzle.a_star import a_star
from n_puzzle.Puzzle import Puzzle
from n_puzzle import euristics


def test_can_reach_finish(puzzle):
    Puzzle.set_side_len(int(len(puzzle) ** 0.5))
    puzzle = Puzzle(puzzle, g=0, h=0, parent=None)
    goal = sorted(puzzle)
    #assert a_star(puzzle, euristics.hemming) == goal
    assert a_star(puzzle, euristics.manhattan) == goal

cProfile.run("test_can_reach_finish([14, 13, 0, 5, 8, 10, 3, 11, 15, 9, 6, 2, 12, 7, 4, 1])")