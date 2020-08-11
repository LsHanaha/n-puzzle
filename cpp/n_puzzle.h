#ifndef N_PUZZLE_H
#define N_PUZZLE_H

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <unordered_map>
#include <vector>

class Puzzle
{
	private:
		__uint128_t		hash = 0;
	public:
		static int			side_len;
		int					g = 0;
		int					h = 0;
		std::vector<int>	map;
		Puzzle				*parent = nullptr;

		Puzzle(std::initializer_list<int> l) { map = l; }
		Puzzle(const std::vector<int> &v) : map(v.begin(), v.end()) {}

		__uint128_t		get_hash() const;

		static void		set_side_len(int len) { side_len = len; }
		int				f() const { return h + g; }

};

class CmpPuzzle // uses gt, as priority_queue sorts by the largest value
{
	public:
		CmpPuzzle() {}
		inline bool operator()(Puzzle *a, Puzzle *b) { return a->f() > b->f(); };
};

bool					lt(const Puzzle *a, const Puzzle *b);

std::vector<Puzzle*>	*get_neighbours(Puzzle *current);

Puzzle	*a_star(Puzzle *current_config, int (*euristic)(const Puzzle *puzzle));

int	hemming(const Puzzle *puzzle);
int	manhattan(const Puzzle *puzzle);
int	phased_manhattan(const Puzzle *puzzle);

#endif
