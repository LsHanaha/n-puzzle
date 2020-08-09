from itertools import permutations
from math import factorial

lst = list(range(9))
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23]

"""
function identify_permutation(perm, chars) {

    for (i = 0; i < length(perm); i++) {
        ids[i] = get_index(perm[i], chars);
    }

    len = length(perm);
    num_chars = length(chars);

    index = 0;
    base = num_chars ^ len - 1;
    for (i = 0; i < length(perm); i++) {
        index += base * ids[i];
        base = base / len;
    }

}
"""

def myhash(lst):
    ids = []
    for elem in lst:
        ids.append(elem)
    index = 0
    base = len(lst) ** len(lst) - 1
    for i in range(len(lst)):
        index += base * ids[i]
        base //= len(lst)
    return index
    
fac = factorial(13)
hashes = dict()
for perm in permutations(lst):
    hashh = myhash(perm)
    assert hashh not in hashes, f"{hashh}, {hashes[hashh]}, {perm}"
    assert hashh < fac
    print(hashh)
    hashes[hashh] = perm
print(fac)