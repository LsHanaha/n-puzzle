#ifndef PUZZLE_HPP
#define PUZZLE_HPP

#include <vector>

class Puzzle
{
	private:
		__uint128_t		hash = 0;
	public:
		static int			side_len;
		int					g;
		int					h;
		std::vector<int>	map;
		Puzzle				*parent = nullptr;

		Puzzle(const std::vector<int> &v = {}) : g(0), h(0), parent(nullptr), map(v) {}
		Puzzle(std::initializer_list<int> l) : Puzzle() { map = l; }

		__uint128_t		get_hash() const;

		static void		set_side_len(int len) { side_len = len; }
		int				f() const { return h + g; }

};

#endif
