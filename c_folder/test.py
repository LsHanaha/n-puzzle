from itertools import permutations

lst = list(range(9))
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23]

def myhash(lst):
    hashh = 0
    for i, j in zip(lst, primes):
        hashh += i * j
    return hashh

hashes = dict()
for perm in permutations(lst):
    hashh = myhash(perm)
    assert hashh not in hashes, f"{hashh}, {hashes[hashh]}, {perm}"
    hashes[hashh] = perm