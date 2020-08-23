from typing import List, Callable
from n_puzzle.heuristics import manhattan, hemming, phased_manh, \
    rowwise_manhattan, uniform
from n_puzzle.a_star import a_star
from n_puzzle.puzzle import Puzzle


class Solver:
    def __init__(self, heuristic, backend):
        self._heuristic = heuristic
        self.backend = backend

    def solve_puzzle(self, size: int, puzzle: List[int]) -> str:
        puzzle_converted = self.converter(puzzle)
        res = PythonBackend(self._heuristic).solve_puzzle(size, puzzle_converted)
        return res

    @staticmethod
    def converter(puzzle: List[int]):
        res = []
        size = len(puzzle) - 1
        for val in puzzle:
            if val == 0:
                res.append(size)
                continue
            res.append(val - 1)
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
            'super': phased_manh,
            'best': rowwise_manhattan,
            'greedy': None,
            'yolo': uniform
        }
        return heuristic.get(self._heuristic)

    def _start_a_star(self, size: int, puzzle: List[int], heuristic: Callable):
        Puzzle.set_side_len(size)
        Puzzle.set_puzzle_len(size*size)
        puzzle = Puzzle(puzzle, g=0, h=None, parent=None)
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
