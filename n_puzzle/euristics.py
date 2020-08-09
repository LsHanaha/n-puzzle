from Puzzle import Puzzle


def hemming(puzzle: Puzzle) -> int:
    out = 0
    for i, elem in enumerate(puzzle):
        if elem:
            out += int(elem != i + 1)
        else:
            out += int(i + 1 != puzzle.side_len ** 2)
    return out


def manhattan(puzzle: Puzzle) -> int:
    out = 0
    for i, elem in enumerate(puzzle):
        current_x = i // puzzle.side_len
        current_y = i % puzzle.side_len
        gold_i = (elem - 1) if elem else (puzzle.side_len ** 2)
        gold_x = gold_i // puzzle.side_len
        gold_y = gold_i % puzzle.side_len
        out += abs(gold_x - current_x) + abs(gold_y - current_y)
    return out
