#include "n_puzzle.h"

int	hemming(const Puzzle *puzzle)
{
	int out = 0;
	for (int i = 0; i < puzzle->map.size(); ++i)
		out += (puzzle->map[i] == i);
	return (out);
}

int	manhattan(const Puzzle *puzzle)
{
	int out = 0;

	int current_x;
	int current_y;
	int gold_x;
	int gold_y;

	for (int i = 0; i < puzzle->map.size(); ++i)
	{
		current_x = i / Puzzle::side_len;
        current_y = i % Puzzle::side_len;
        gold_x = puzzle->map[i] / Puzzle::side_len;
        gold_y = puzzle->map[i] % Puzzle::side_len;
		out += abs(gold_x - current_x) + abs(gold_y - current_y);
	}

	return (out);
}
