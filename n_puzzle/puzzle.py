class Puzzle:
    side_len = None
    puzzle_len = None
    __slots__ = "g", "h", "parent", "move", 'board', 'hash'

    def __init__(self, *args, **kwargs):
        self.board = args[0]
        self.g = kwargs.pop("g")
        self.h = kwargs.pop("h")
        self.parent = kwargs.pop("parent")
        self.move = None
        self.hash = self.__str__()

    def __str__(self):
        str_hash = ""
        for i, val in enumerate(self.board):
            str_hash += str(val)
            if i + 1 % self.side_len == 0:
                str_hash += '\n'
        return str_hash

    def __hash__(self):
        ids = []
        length = self.puzzle_len
        for elem in self.board:
            ids.append(elem)
        out = 0
        base = length ** length - 1
        for i in range(length):
            out += base * ids[i]
            out //= length
        return out

    def set_move(self, move):
        self.move = move

    def __lt__(self, other):
        return self.f < other.f

    @property
    def f(self):
        return self.g + self.h

    @staticmethod
    def set_side_len(side_len: int) -> None:
        assert isinstance(side_len, int)
        Puzzle.side_len = side_len

    @staticmethod
    def set_puzzle_len(puzzle_len: int) -> None:
        Puzzle.puzzle_len = puzzle_len
