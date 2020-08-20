import argparse
import sys
from typing import Optional, List, Tuple, Union


class GetPuzzle:

    def get_puzzle(self, args: argparse.Namespace) -> Tuple[int, List[int]]:
        print(args)
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
            raise BrokenPipeError("Отсутсвуют данные в файле")
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
            raise ValueError("В массив паздла передано не целое число.")
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
                             "Значения пазла дожны раполагаться в интервале [0, size*size - 1)."
                             " Повторы чисел недопустимы.")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-s", "--size", type=int, default=None,
                        help="Size of the puzzle's side. Must be >= 3.")
    parser.add_argument("-p", "--puzzle", type=int, nargs='+',
                        help="puzzle himself.")
    parser.add_argument("-f", "--file", type=str, default=False,
                        help="Forces generation of an unsolvable puzzle")

    args = parser.parse_args()
    # read_puzzle(args)
    error = False
    try:
        size, puzzle = GetPuzzle().get_puzzle(args)
    except ValueError as e:
        print(e)
        error = True
    finally:
        if not sys.stdin.isatty():
            sys.stdin.read()
    if error:
        exit()

if __name__ == "__main__":
    main()
