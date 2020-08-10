#include "n_puzzle.h"

typedef std::unordered_map<__uint128_t, Puzzle *> puzzle_map;
typedef std::priority_queue<Puzzle*, std::vector<Puzzle*>, CmpPuzzle> puzzle_q;

// дебажное
void	print_puzzle(Puzzle *puzzle)
{
	for (int i = 0; i < puzzle->map.size(); ++i)
		std::cout << puzzle->map[i] << ((i % Puzzle::side_len == Puzzle::side_len - 1) ? "\n" : " ");
	std::cout << "\n\n";
}

// дебажное
void	print(Puzzle *puzzle)
{
	std::cout << "puzzle:\n";
	print_puzzle(puzzle);
	std::cout << "from:\n";
	if (puzzle->parent != nullptr)
		print_puzzle(puzzle->parent);
	std::cout << "g=" << puzzle->g << ",h=" << puzzle->h << ",f=" << puzzle->f() << "\n\n================\n";
}

Puzzle	*a_star(Puzzle *current_config, int (*euristic)(const Puzzle *puzzle))
{
	puzzle_map visited;
	puzzle_q q;
	std::vector<Puzzle*> *neighbours;
	__uint128_t permutation_id;
	puzzle_map::iterator iter;

	while (euristic(current_config))
	{
		visited[current_config->get_hash()] = current_config;
		neighbours = get_neighbours(current_config);
		for (Puzzle *&neighbour: *neighbours)
		{
			permutation_id = neighbour->get_hash();
			iter = visited.find(permutation_id);
			if (iter == visited.end()) // not in visited
			{
				neighbour->h = euristic(neighbour);
				q.push(neighbour);
			}
			else if (current_config->g + 1 < (*iter).second->g)
			{
				(*iter).second->g = current_config->g + 1;
				(*iter).second->parent = current_config;
			}
		}
		delete neighbours;
		if (q.size() == 0)	// отлова ошибок ради, потом можно убрать
			throw;
		current_config = q.top();
		q.pop();
	}
	return (current_config);
}
