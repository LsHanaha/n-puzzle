import pytest
from n_puzzle.Puzzle import Puzzle
from n_puzzle.get_neighbours import get_neighbours


@pytest.mark.parametrize("puzzle,results", [
     [ [11, 10, 15,  2, 5,  9, 13,  6,  4, 3, 7, 12, 1,  8,  0, 14],
      [[11, 15, 10,  2, 5,  9, 13,  6,  4, 3, 7, 12, 1,  8,  0, 14],
       [11, 10,  2, 15, 5,  9, 13,  6,  4, 3, 7, 12, 1,  8,  0, 14],
       [11, 10, 13,  2, 5,  9, 15,  6,  4, 3, 7, 12, 1,  8,  0, 14]]],
    [[15, 10, 11,  2, 5,  9, 13,  6, 4,  3,  7, 12, 1,  8,  0, 14],
     [[10, 15, 11,  2, 5,  9, 13,  6, 4,  3,  7, 12, 1,  8,  0, 14],
     [5, 10, 11,  2, 15,  9, 13,  6, 4,  3,  7, 12, 1,  8,  0, 14]]],
    [
        [2, 10, 11,  15, 5,  9, 13,  6, 4,  3,  7, 12, 1,  8,  0, 14],

        [[2, 10, 15,  11, 5,  9, 13,  6, 4,  3,  7, 12, 1,  8,  0, 14],
        [2, 10, 11,  6, 5,  9, 13,  15, 4,  3,  7, 12, 1,  8,  0, 14]]
    ],
    [
        [11, 10, 14,  2, 5,  9, 13,  6,  4, 3, 7, 12, 1,  8,  0, 15],

        [[11, 10, 14,  2, 5,  9, 13,  6,  4, 3, 7, 15, 1,  8,  0, 12],
        [11, 10, 14,  2, 5,  9, 13,  6,  4, 3, 7, 12, 1,  8,  15, 0]]
    ],
    [
        [11, 10, 14,  2, 5,  9, 13,  6,  4, 3, 7, 12, 15,  8,  0, 11],

        [[11, 10, 14,  2, 5,  9, 13,  6,  15, 3, 7, 12, 4,  8,  0, 11],
         [11, 10, 14,  2, 5,  9, 13,  6,  4, 3, 7, 12, 8,  15,  0, 11]]
    ]
])
def test_surrounded_but_not_a_pigeon(puzzle, results):
    Puzzle.set_side_len(int(len(puzzle) ** 0.5))
    puzzle = Puzzle(puzzle, g=0, h=0, parent=None)
    neighbours = get_neighbours(puzzle)

    for neighbour, res in zip(neighbours, results):
        assert neighbour == res
    assert len(neighbours) == len(results)
