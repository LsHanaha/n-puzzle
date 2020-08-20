import argparse
import sys
from typing import Optional, List, Tuple, Union
from puzzle_checker import is_solvable


class GetPuzzle:

    def get_puzzle(self, args: argparse.Namespace) -> Tuple[int, List[int]]:
        if args.puzzle:
            size, puzzle = self._read_args(args)
        elif args.file:
            size, puzzle = self._read_file(args)
        else:
            size, puzzle = self._read_pipe()

        return size, puzzle

    def _read_pipe(self) -> Tuple[int, List[int]]:
        data = []
        for row in sys.__stdin__:
            data.append(row)
        if not data:
            raise BrokenPipeError("Отсутсвуют данные в Pipe")
        size, puzzle = self._read_puzzle(data)
        return size, puzzle

    def _read_file(self, args: argparse.Namespace) -> Tuple[int, List[int]]:
        filename = args.file

        data = []
        with open(filename, encoding="utf-8") as file:
            for row in file:
                data.append(row)
        if not data:
            raise ValueError("Отсутсвуют данные в файле")
        size, puzzle = self._read_puzzle(data)
        return size, puzzle

    def _read_args(self, args: argparse.Namespace) -> Tuple[int, List[int]]:
        size = args.size
        puzzle = args.puzzle
        self._check_symbols(size, puzzle)
        return size, puzzle

    def _read_puzzle(self, raw_puzzle: List[str]) -> Tuple[int, List[int]]:
        data = []
        for row in raw_puzzle:
            if "#" in row:
                row = row[:row.index('#')]
            if row:
                data.append(row.strip())

        if data:
            size = data.pop(0)
            if isinstance(size, str) and size.isdigit():
                size = int(size)
            else:
                raise ValueError("Значение размера должно быть целым числом")

            puzzle = self.__convert_list_to_int(data)
            self._check_symbols(size, puzzle)
            return size, puzzle
        raise ValueError("Переданы некорректные данные. Не обнаружены цифры.")

    @staticmethod
    def __convert_list_to_int(array: List[str]) -> List[int]:
        try:
            res = [int(i) for i in array]
        except ValueError:
            raise ValueError("В пазле обнаружен не валидный элемент. Ожидается набор целых чисел")
        return res

    @staticmethod
    def _check_symbols(size: int, puzzle: List[Union[int, str]]) -> None:

        if size is None or not isinstance(size, int):
            raise ValueError("Значение размера должно быть целым числом")
        if size < 2:
            raise ValueError("Значение size должно быть больше 1")

        valid_puzzle = [i for i in range(size * size)]
        if sorted(puzzle) != valid_puzzle:
            raise ValueError("Подан некорректный пазл. Проверьте символы и их колличество. "
                             "Значения пазла дожны раполагаться в интервале [0, size*size - 1]."
                             " Повторы чисел недопустимы.")


class HandleResult:
    def __init__(self, start: List[int], size: int):
        self._start = start
        self._size = size

    def show_result(self, solution: str, quiet: bool):
        print("Solution: ", solution)
        if not quiet:
            print('=' * (self._size * 4))
            print("Start config:")
            self._print_puzzle(self._start)
            step = self._start

            for move in solution:
                print(move)
                step, switch = self._move_empty_square(step, move)
                self._print_puzzle(step, switch)

    def _print_puzzle(self, puzzle: List[int], switch: Optional[int] = None):
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


def activate_tty():
    parser = argparse.ArgumentParser(description="Add some arguments or use pipe. It's up to you")
    parser.add_argument("-s", "--size", type=int, default=None,
                        help="Size of the puzzle's side. Must be >= 2.")
    parser.add_argument("-p", "--puzzle", type=int, nargs='+',
                        help="Puzzle himself")
    parser.add_argument("-f", "--file", type=str, default=False,
                        help="Read puzzle from file")
    parser.add_argument("-q", default=False, action="store_true",
                        help="Quiet mode.")
    parser.add_argument("-v", default=False, action="store_true",
                        help="Activate advanced output information.")
    parser.add_argument("-e", type=str, default='manh',
                        help="Choose heuristic for solution. Default is simple manhattan. "
                             "Available:\n manh - manhattan(default);\nheim - Haimling;\n"
                             "super - upgraded manhattan;\nbest - the best manhattan;\n"
                             "greedy - activate greedy mode;\nyolo - fuck mandatory, cause yolo!;")

    args = parser.parse_args()
    return args


def read_puzzle(args: argparse.Namespace) -> Tuple[int, List[int]]:
    error = False

    try:
        size, puzzle = GetPuzzle().get_puzzle(args)
    except (ValueError, BrokenPipeError) as e:
        print(e, " \nЗавершаем работу приложения.")
        error = True
    finally:
        if not sys.stdin.isatty():
            sys.stdin.read()

    if error:
        exit()
    return size, puzzle


def main():

    args = activate_tty()
    size, puzzle = read_puzzle(args)
    if not is_solvable(puzzle):
        print(f"Паззл '{', '.join([str(i) for i in puzzle])}' не имеет решения."
              f"\nЗавершаем работу приложения")
        exit()

    # print(size, puzzle)
    HandleResult(puzzle, size).show_result("llllrrrrud", args.q or args.v)


if __name__ == "__main__":
    main()
