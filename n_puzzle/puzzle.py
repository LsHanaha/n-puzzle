class Puzzle(list):
    side_len = None
    __slots__ = "g", "h", "parent", "move"

    def __init__(self, *args, **kwargs):
        self.g = kwargs.pop("g")
        self.h = kwargs.pop("h")
        self.parent = kwargs.pop("parent")
        self.move = None
        super().__init__(*args, **kwargs)

    def __hash__(self):
        ids = []
        length = len(self)
        for elem in self:
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
    def set_side_len(side_len):
        assert isinstance(side_len, int)
        Puzzle.side_len = side_len
