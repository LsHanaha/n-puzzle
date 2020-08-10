#include "n_puzzle.h"

static Puzzle*
cook_new_map(Puzzle *current, int empty_id, int new_id)
{
	Puzzle *out = new Puzzle(current->map);
	std::swap(out->map[empty_id], out->map[new_id]);
	out->g = current->g + 1;
	out->parent = current;
	return (out);
}

static int	locate_empty_tile(Puzzle *current)
{
	for (int i = 0; i < current->map.size(); ++i)
		if (current->map[i] == current->map.size() - 1)
			return (i);
	throw;
}

std::vector<Puzzle*>*
get_neighbours(Puzzle *current)
{
	std::vector<Puzzle*> *result = new std::vector<Puzzle*>();
	int empty_id = locate_empty_tile(current);

	if (empty_id - Puzzle::side_len >= 0)
		result->push_back(cook_new_map(current, empty_id, empty_id - Puzzle::side_len));
	if (empty_id % Puzzle::side_len - 1 >= 0)
		result->push_back(cook_new_map(current, empty_id, empty_id - 1));
	if (empty_id % Puzzle::side_len + 1 < Puzzle::side_len)
		result->push_back(cook_new_map(current, empty_id, empty_id + 1));
	if (empty_id + Puzzle::side_len < current->map.size())
		result->push_back(cook_new_map(current, empty_id, empty_id + Puzzle::side_len));

	return result;
}
