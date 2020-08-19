#include "n_puzzle.hpp"

#include <iostream>

int	hemming(const Puzzle *puzzle)
{
	int out = 0;
	for (int i = 0; i < static_cast<int>(puzzle->map.size()); ++i)
		out += (puzzle->map[i] != i);
	return (out);
}

inline static int get_manhattan_score(int map_i, int i, int side_len)
{
	return abs(map_i / side_len - i / side_len)
			+ abs(map_i % side_len - i % side_len);
}

int	manhattan(const Puzzle *puzzle)
{
	int out = 0;

	for (int i = 0; i < static_cast<int>(puzzle->map.size()); ++i)
		out += get_manhattan_score(puzzle->map[i], i, Puzzle::side_len);
	return (out);
}

int	phased_manhattan(const Puzzle *puzzle)
{
	int out = 0;

	for (int i = 0; i < static_cast<int>(puzzle->map.size()); ++i)
	{
		if (puzzle->map[i] < Puzzle::side_len * (Puzzle::side_len - 2))
			out += get_manhattan_score(puzzle->map[i], i, Puzzle::side_len) * 4;
		else if (puzzle->map[i] % Puzzle::side_len < Puzzle::side_len - 2)
			out += get_manhattan_score(puzzle->map[i], i, Puzzle::side_len) * 2;
		else
			out += get_manhattan_score(puzzle->map[i], i, Puzzle::side_len);
	}
	return out;
}

static void init_weights(std::vector<int>& weights)
{
	weights.resize(Puzzle::side_len * Puzzle::side_len, 1);
	for (int i = weights.size() - 1; i >= 0; --i)
	{
		if (i / Puzzle::side_len < Puzzle::side_len - 2)
		{
			weights[i] = (Puzzle::side_len - i / Puzzle::side_len) * 2;
		}
		else if (i % Puzzle::side_len < Puzzle::side_len - 2)
		{
			weights[i] = (Puzzle::side_len - i / Puzzle::side_len);
			weights[i] += Puzzle::side_len - i % Puzzle::side_len;
		}
	}
}

int	rowwise_manhattan(const Puzzle *puzzle)
{
	int out = 0;
	static std::vector<int> weights;

	if (!weights.size())
		init_weights(weights);
	for (int i = 0; i < static_cast<int>(puzzle->map.size()); ++i)
		out += get_manhattan_score(puzzle->map[i], i, Puzzle::side_len) * weights[puzzle->map[i]];
	return out;
}

int	uniform(const Puzzle *puzzle)
{
	for (int i = 0; i < static_cast<int>(puzzle->map.size()); ++i)
		if (puzzle->map[i] != i)
			return (1);
	return (0);
}

int	greedy_manhattan(const Puzzle *puzzle)
{
	//hacky-hacky.
	uintptr_t addr = reinterpret_cast<uintptr_t>(puzzle);
	Puzzle* deconst = reinterpret_cast<Puzzle*>(addr);
	deconst->g = 0;
	return manhattan(puzzle);
}
