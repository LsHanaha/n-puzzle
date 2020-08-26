from typing import List, Optional


class HandleResult:
    def __init__(self, start: List[int], size: int):
        self._start = start
        self._size = size

    def show_result(self, solution: str, quiet: bool):
        print("Solution: ", solution or "empty")

        if not quiet:
            print('=' * (self._size * 4))
            print("Start config:")
            self.print_puzzle(self._start)
            step = self._start

            for move in solution:
                print(move)
                step, switch = self._move_empty_square(step, move)
                self.print_puzzle(step, switch)

    def print_puzzle(self, puzzle: List[int], switch: Optional[int] = None):
        for i, val in enumerate(puzzle):
            if not val:
                print('\033[31m{:2}\033[0m'.format(val), end=" ")
            elif val == switch:
                print('\033[32m{:2}\033[0m'.format(val), end=" ")
            else:
                print("{:2}".format(val), end=" ")
            if (i + 1) % self._size == 0:
                print()
        print('=' * (self._size * 4))

    def _move_empty_square(self, arr: List[int], move: str):
        zero_id = arr.index(0)
        if move == 'u':
            arr[zero_id], arr[zero_id - self._size] = arr[zero_id - self._size], arr[zero_id]
        elif move == 'l':
            arr[zero_id], arr[zero_id - 1] = arr[zero_id - 1], arr[zero_id]
        elif move == 'r':
            arr[zero_id], arr[zero_id + 1] = arr[zero_id + 1], arr[zero_id]
        elif move == 'd':
            arr[zero_id], arr[zero_id + self._size] = arr[zero_id + self._size], arr[zero_id]
        return arr, arr[zero_id]
