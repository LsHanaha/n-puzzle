class Puzzle(list):
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
