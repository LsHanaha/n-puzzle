#ifndef N_PUZZLE_HPP
#define N_PUZZLE_HPP

#include "Puzzle.hpp"
#include <string>

class CmpPuzzle // uses gt, as priority_queue sorts by the largest value
{
	public:
		CmpPuzzle() {}
		inline bool operator()(Puzzle *a, Puzzle *b) { return a->f() > b->f(); };
};

bool    lt(const Puzzle *a, const Puzzle *b);

std::vector<Puzzle*>    *get_neighbours(Puzzle *current);

std::string a_star(Puzzle *current_config, const puzzle_config_t& goal,
		int (*heuristic)(const Puzzle *puzzle, const puzzle_config_t& goal));

std::string get_sequence(Puzzle *solution);

int	hemming(const Puzzle *puzzle, const puzzle_config_t& goal);
int	manhattan(const Puzzle *puzzle, const puzzle_config_t& goal);
int	phased_manhattan(const Puzzle *puzzle, const puzzle_config_t& goal);
int	rowwise_manhattan(const Puzzle *puzzle, const puzzle_config_t& goal);

int	uniform(const Puzzle *puzzle, const puzzle_config_t& goal);
int	greedy_manhattan(const Puzzle *puzzle, const puzzle_config_t& goal);

#endif