from n_puzzle.Puzzle import Puzzle


def hemming(puzzle: Puzzle) -> int:
    out = 0
    for i, elem in enumerate(puzzle):
        out += int(elem != i)
    return out


def manhattan(puzzle: Puzzle) -> int:
    out = 0
    for i, elem in enumerate(puzzle):
        current_x = i // puzzle.side_len
        current_y = i % puzzle.side_len
        gold_x = elem // puzzle.side_len
        gold_y = elem % puzzle.side_len
        out += abs(gold_x - current_x) + abs(gold_y - current_y)
    return out
