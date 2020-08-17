
from math import sqrt


def is_solvable(puzzle: list):
    res = 0
    size = len(puzzle)
    for i, checker in enumerate(puzzle[:-1]):
        if checker == size - 1:
            continue
        for checked in puzzle[i + 1:]:
            if checked == size - 1:
                continue
            if checker > checked:
                res += 1
    # if size % 2 == 0:
    zero_id = int(puzzle.index(size - 1) / int(sqrt(size))) + 1
    # else:
    #     zero_id = 0
    return (zero_id + res) % 2 == 0


def is_solvable2(puzzle):
    res = 0

    size = len(puzzle)
    for i in range(size - 1):
        for j in range(i+1, size):
            if puzzle[j] and puzzle[i] and puzzle[i] > puzzle[j]:
                res += 1
    if size % 2:
        return res % 2 == 0
    zero_id = int(puzzle.index(size - 1) / sqrt(size)) + 1
    return (res + zero_id) % 2 == 1



def is_solvable3(tiles):
    count = 0

    size = len(tiles)
    for i in range(size - 1):
        for j in range(i+1, size):
            if tiles[j] and tiles[i] and tiles[i] > tiles[j]:
                count += 1

    return count % 2 == 0


def is_solvable4(puzzle):
    inv_count = 0
    size = len(puzzle)
    for i in range(size - 1):
        for j in range(i + 1, size):
            if (puzzle[j] and puzzle[i]) and (puzzle[i] > puzzle[j]):
                inv_count += 1
    print(inv_count)
    return inv_count % 2 == 0


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

# def shit_shape(puzzle):
#     1, 2, 3, 4,
#     12, 13, 14, 5,
#     11, 0, 15, 6,
#     10, 9, 8, 7
#     side_len = int(sqrt(len(puzzle)))
#     temp = []
#     res = []
#

if __name__ == "__main__":
    my_test = [15,
 0,
13,
 2,
 7,
10,
11,
 6,
 3,
 5,
 1,
12,
 8,
 9,
14,
 4]
    res = normal_shape(my_test)
    print(res)

