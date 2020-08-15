from n_puzzle.Puzzle import Puzzle


def hemming(puzzle: Puzzle) -> int:
    out = 0
    for i, elem in enumerate(puzzle):
        out += int(elem != i)
    return out


def get_manhattan_score(puzzle, elem, i):
    current_x = i // puzzle.side_len
    current_y = i % puzzle.side_len
    gold_x = elem // puzzle.side_len
    gold_y = elem % puzzle.side_len
    return abs(gold_x - current_x) + abs(gold_y - current_y)


def manhattan(puzzle: Puzzle) -> int:
    out = 0
    for i, elem in enumerate(puzzle):
        out += get_manhattan_score(puzzle, elem, i)
    return out


# int	phased_manhattan(const Puzzle *puzzle)
# {
# 	int out[3] {0};
#
# 	for (int i = 0; i < puzzle->map.size(); ++i)
# 	{
# 		if (puzzle->map[i] < Puzzle::side_len * (Puzzle::side_len - 2))
# 			out[0] += get_manhattan_score(puzzle->map[i], i, Puzzle::side_len);
# 		else if (puzzle->map[i] % Puzzle::side_len < Puzzle::side_len - 2)
# 			out[1] += get_manhattan_score(puzzle->map[i], i, Puzzle::side_len);
# 		else
# 			out[2] += get_manhattan_score(puzzle->map[i], i, Puzzle::side_len);
# 	}
# 	return out[0] * 4 + out[1] * 2 + out[2];
# }