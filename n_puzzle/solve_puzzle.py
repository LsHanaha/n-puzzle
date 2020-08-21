from typing import List, Callable
from n_puzzle.heuristics import manhattan, hemming
from n_puzzle.a_star import a_star
from n_puzzle.puzzle import Puzzle


class Solver:
    def __init__(self, heuristic, backend):
        self._heuristic = heuristic
        self.backend = backend

    def solve_puzzle(self, size: int, puzzle: List[int]) -> str:
        converted_puzzle = self.converter(puzzle.copy())
        res = PythonBackend(self._heuristic).solve_puzzle(size, converted_puzzle)
        return res

    @staticmethod
    def converter(puzzle: List[int]):
        res = []
        size = len(puzzle) - 1
        for val in puzzle:
            if val == size:
                res.append(0)
                continue
            res.append(val + 1)
        return res

    def select_backend(self):
        pass


class PythonBackend:
    def __init__(self, heu):
        self._heuristic = heu

    def solve_puzzle(self, size: int, puzzle: List[int]):
        heuristic = self._select_heuristic()
        res = self._start_a_star(size, puzzle, heuristic)
        return res

    def _select_heuristic(self):

        heuristic = {
            "manh": manhattan,
            'heim': hemming,
            'super': None,
            'best': None,
            'greedy': None,
            'yolo': None
        }
        return heuristic.get(self._heuristic)

    def _start_a_star(self, size: int, puzzle: List[int], heuristic: Callable):
        Puzzle.set_side_len(size)
        puzzle = Puzzle(puzzle, g=0, h=0, parent=None)
        finish_state = a_star(puzzle, heuristic)
        res = self._restore_path(finish_state)
        return res

    @staticmethod
    def _restore_path(finish: Puzzle) -> str:
        res = []
        current = finish
        while current.parent:
            res.insert(0, current.move)
            current = current.parent
        return ''.join(res)
