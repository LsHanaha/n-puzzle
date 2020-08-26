#include "n_puzzle.hpp"
#include <iostream>
#include <queue>
#include <unordered_map>

typedef std::unordered_map<std::string, Puzzle *> puzzle_map;
typedef std::priority_queue<Puzzle*, std::vector<Puzzle*>, CmpPuzzle> puzzle_q;

static void
clear_memory(puzzle_map& visited, puzzle_q& q)
{
	for (auto &elem: visited)
		delete elem.second;
	while (!q.empty())
	{
		Puzzle *current = q.top();
		q.pop();
		delete current;
	}
}

inline static Puzzle*
is_in(Puzzle *current_config, puzzle_map& visited)
{
	puzzle_map::iterator iter = visited.find(current_config->get_hash());
	if (iter != visited.end())
		return iter->second;
	else
		return nullptr;
}

inline static Puzzle*
pop(puzzle_q& q)
{
	if (q.size() == 0)
			throw std::runtime_error("Queue cannot be empty");
	Puzzle	*out = q.top();
	q.pop();
	return out;
}

std::string
a_star(Puzzle *current_config, const puzzle_config_t& goal,
		int (*heuristic)(const Puzzle *puzzle, const puzzle_config_t& goal))
{
	puzzle_map	visited;
	puzzle_q	q;
	Puzzle		*found_elem;

	while (heuristic(current_config, goal))
	{
		if ((found_elem = is_in(current_config, visited)))
		{
			delete current_config;
			current_config = pop(q);
			continue;
		}
		visited[current_config->get_hash()] = current_config;
		std::vector<Puzzle*> neighbours = get_neighbours(current_config);
		for (Puzzle *neighbour: neighbours)
		{
			if (!(found_elem = is_in(neighbour, visited)))
			{
				neighbour->h = heuristic(neighbour, goal);
				q.push(neighbour);
			}
			else
			{
				if (current_config->g + 1 < found_elem->g)
				{
					found_elem->g = current_config->g + 1;
					found_elem->parent = current_config;
				}
				delete neighbour;
			}
		}
		current_config = pop(q);
	}
	std::cout << "Total states visited:   " << visited.size() << std::endl;
	std::cout << "Total states in memory: " << visited.size() + q.size() << std::endl;
	std::string	move_sequence = get_sequence(current_config);
	delete current_config;
	clear_memory(visited, q);
	return (move_sequence);
}
