from n_puzzle.puzzle import Puzzle


target_indexes = []
target_map = []


def hemming(puzzle: Puzzle) -> int:
    out = 0
    for i, elem in enumerate(puzzle.board):
        out += int(elem != target_map[i])
    return out


def get_manhattan_score(side_len: int, elem: int, i: int) -> int:
    current_y = i // side_len
    current_x = i % side_len
    goal_y, goal_x = target_indexes[elem]
    return abs(goal_x - current_x) + abs(goal_y - current_y)


def manhattan(puzzle: Puzzle) -> int:
    out = 0
    for i, elem in enumerate(puzzle.board):
        out += get_manhattan_score(puzzle.side_len, elem, i)
    return out


def phased_manh(puzzle: Puzzle) -> int:
    out = 0

    for i in range(puzzle.puzzle_len):
        if puzzle.board[i] < puzzle.side_len * (puzzle.side_len - 2):
            out += get_manhattan_score(puzzle.side_len, puzzle.board[i], i) * 4
        elif puzzle.board[i] % puzzle.side_len < puzzle.side_len - 2:
            out += get_manhattan_score(puzzle.side_len, puzzle.board[i], i) * 2
        else:
            out += get_manhattan_score(puzzle.side_len, puzzle.board[i], i)
    return out


def init_weights(weights: list, puzzle: Puzzle):

    for i in range(puzzle.puzzle_len - 1, -1, -1):
        if i / puzzle.side_len < puzzle.side_len - 2:
            weights[i] = (puzzle.side_len - int(i / puzzle.side_len)) * 2
        elif i % puzzle.side_len < puzzle.side_len - 2:
            weights[i] = puzzle.side_len - int(i / puzzle.side_len)
            weights[i] += puzzle.side_len - i % puzzle.side_len


def rowwise_manhattan(puzzle: Puzzle):

    out = 0
    weights = [1 for i in range(puzzle.puzzle_len)]

    if not weights:
        init_weights(weights, puzzle)
    for i in range(puzzle.puzzle_len):
        out += get_manhattan_score(puzzle.side_len, puzzle.board[i], i) * weights[puzzle.board[i]]
    return out


def uniform(puzzle: Puzzle) -> int:

    for i in range(puzzle.puzzle_len):
        if puzzle.board[i] != target_map[i]:
            return 1
    return 0


def greedy(puzzle: Puzzle):

    puzzle.g = 0
    return phased_manh(puzzle)
