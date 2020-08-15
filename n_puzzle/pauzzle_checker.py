
from math import sqrt




def count_sum(puzzle: list):
    res = 0
    size = len(puzzle)
    for i in range(size - 1):
        if puzzle[i] == size - 1 or puzzle[i + 1] == size - 1:
            continue
        if puzzle[i] > puzzle[i + 1]:
            res += 1

    zero_id = int(puzzle.index(size - 1) / int(sqrt(size))) + 1
    print(zero_id + res)
    assert (zero_id + res) % 2 == 0
    print(zero_id + res)


a = [4, 13, 10,  9,  4,  6, 15,  0,  7,  5,  2,  8, 11,  1,  3, 12, 14]
if __name__ == "__main__":
    count_sum([8, 1, 4,14,11,15, 0, 6, 5, 9, 3,10, 2,13, 7,12])

