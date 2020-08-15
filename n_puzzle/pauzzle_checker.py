
from math import sqrt


def count_sum(puzzle: list):
    res = 0
    size = len(puzzle)
    for i in range(size - 1):
        if puzzle[i] == size - 1:
            continue
        for j in range(i + 1, size):
            if puzzle[j] == size - 1:
                continue
            if puzzle[i] > puzzle[j]:
                res += 1

    zero_id = int(puzzle.index(size - 1) / int(sqrt(size))) + 1
    print(zero_id + res)
    assert (zero_id + res) % 2 == 0
    print(zero_id + res)


a = [4, 5, 8, 12, 10, 13, 15, 3, 11, 2, 0, 14, 9, 6, 7, 1]
if __name__ == "__main__":
    count_sum(a)

