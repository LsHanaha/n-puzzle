class Puzzle(list):
    def __init__(self, *args, **kwargs):
        self.g = kwargs.pop("g")
        self.h = kwargs.pop("h")
        self.parent = kwargs.pop("parent")
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

    def __lt__(self, other):
        return self.f < other.f

    @property
    def f(self):
        return self.g + self.h

    def __repr__(self):
        return f"||parent = {self.parent}, sum = {self.f}||"


if __name__ == '__main__':
    import heapq
    import random

    queue = []
    heapq.heapify(queue)

    for i in range(40):
        new_obj = Puzzle(g=random.randint(1, 1000), h=random.randint(1, 1000), parent=str(i))
        heapq.heappush(queue, new_obj)

    for i in range(40):
        print(heapq.heappop(queue))




