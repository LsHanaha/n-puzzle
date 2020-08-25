from typing import List, Callable, Tuple
from n_puzzle.heuristics import manhattan, hamming, phased_manh, \
    rowwise_manhattan, uniform, greedy, target_indexes, target_map
from n_puzzle.a_star import a_star
from n_puzzle.puzzle import Puzzle
from n_puzzle.converters import convert_to_indexes
import cpp_backend


class Solver:
    def __init__(self, heuristic: str, is_cpp: bool):
        self._heuristic = heuristic
        self._backend = self.__select_backend(is_cpp)

    @staticmethod
    def __select_backend(is_cpp):
        if is_cpp:
            return CPPBackend
        else:
            return PythonBackend

    def solve_puzzle(self, size: int, puzzle: List[int], goal: List[int]) -> str:
        """типа возвращает строку движений lrrruddd..."""
        res = self._backend().solve_puzzle(size, puzzle, goal, self._heuristic)
        return res


class CPPBackend:

    @staticmethod
    def convert_notation(puzzle: List[int]) -> List[int]:
        return [(i - 1) if i else (len(puzzle) - 1) for i in puzzle]

    @staticmethod
    def encode_goal(puzzle: List[int]) -> List[int]:
        return [puzzle.index(i) for i in range(len(puzzle))]

    @staticmethod
    def solve_puzzle(size: int,
                     puzzle: List[int],
                     goal: List[int],
                     heuristic: str) -> str:
        puzzle = CPPBackend.convert_notation(puzzle)
        goal = CPPBackend.encode_goal(CPPBackend.convert_notation(goal))
        return cpp_backend.solve(size, puzzle, goal, heuristic)


class PythonBackend:

    @staticmethod
    def _convert_goal_to_indexes(puzzle: List[int], size: int) -> List[Tuple[int, int]]:
        goal = convert_to_indexes(puzzle, size)
        return goal

    def solve_puzzle(self, size: int, puzzle: List[int], goal: List[int], heu: str) -> str:
        heuristic = self._select_heuristic(heu)

        goal_indexes = self._convert_goal_to_indexes(goal, size)
        # так грязно...
        target_map.extend(goal)
        target_indexes.extend(goal_indexes)

        res = self._start_a_star(size, puzzle, goal_indexes, heuristic)
        return res

    @staticmethod
    def _select_heuristic(heu: str) -> Callable:

        heuristic = {
            "manh": manhattan,
            'hamm': hamming,
            'super': phased_manh,
            'best': rowwise_manhattan,
            'greedy': greedy,
            'yolo': uniform
        }
        return heuristic.get(heu)

    def _start_a_star(self, size: int, puzzle: List[int], goal: List[Tuple[int, int]],
                      heuristic: Callable):
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
