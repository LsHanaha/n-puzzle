#ifndef PUZZLE_HPP
#define PUZZLE_HPP

#include <string>
#include <vector>

typedef std::string	puzzle_config_t;

class Puzzle
{
	public:
		static int			side_len;
		int					g;
		int					h;
		puzzle_config_t		map;
		Puzzle				*parent;

		Puzzle() = delete;
		Puzzle(const puzzle_config_t &v) : g(0), h(0), map(v), parent(nullptr) {}

		const std::string&	get_hash() const { return map; }

		static void			set_side_len(int len) { side_len = len; }
		int					f() const { return h + g; }
};

#endif
