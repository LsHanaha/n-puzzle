
from math import sqrt


def is_solvable(puzzle):
    res = 0

    size = len(puzzle)
    for i in range(size - 1):
        if not puzzle[i]:
            continue
        for j in range(i+1, size):
            if puzzle[j] and puzzle[i] and puzzle[i] > puzzle[j]:
                res += 1
    print("res = ", res) # 13 12 6 11 10 6 5 7 5 5 1 3 2 1
    # [0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1] 14 13 12 11 10 9 8 7 6 5 4 3 2 1
    if size % 2:
        return res % 2 == 0
    zero_id = puzzle.index(0) // sqrt(size) + 1
    print("zero_id = ", zero_id)
    return (res + zero_id) % 2 == 0


def converter(puzzle):
    if isinstance(puzzle, str):
        puzzle = [int(i) for i in puzzle]
    res = []
    size = len(puzzle) - 1
    for val in puzzle:
        if val == size:
            res.append(0)
            continue
        res.append(val + 1)
    return res


def normal_shape(puzzle):
    side_len = int(sqrt(len(puzzle)))
    res = []

    for i, value in enumerate(puzzle[::side_len]):
        if i % 2 == 0:
            brick = puzzle[i * side_len: (i + 1) * side_len]
        else:
            brick = puzzle[i * side_len: (i + 1) * side_len]
            brick = brick[::-1]
        res.extend(brick)
    return res


def shit_shape(puzzle):

    puzzle_len = len(puzzle)
    side_len = int(sqrt(puzzle_len))
    puzzle_2d = [puzzle[i:i+side_len] for i in range(0, puzzle_len, side_len)]

    res = [*puzzle_2d.pop(0)]
    while puzzle_2d:
        puzzle_2d = [row for row in zip(*puzzle_2d)][::-1]
        res.extend(puzzle_2d.pop(0))
    return res


if __name__ == "__main__":
    my_test = [0,14,13,7,15,12,8,6,11,9,5,2,10,4,3,1]
    res = is_solvable2(my_test)
    print(res)

