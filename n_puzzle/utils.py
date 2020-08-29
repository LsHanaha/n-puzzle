import os
import sys


class Suppresser:
    def __enter__(self):
        self.stdout = sys.stdout
        sys.stdout = open(os.devnull, "w")
        return self

    def __exit__(self, *args):
        sys.stdout = self.stdout
