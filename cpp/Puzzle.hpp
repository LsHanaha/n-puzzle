#ifndef PUZZLE_HPP
#define PUZZLE_HPP

#include <string>
#include <vector>

typedef std::vector<int>	puzzle_config_t;

class Puzzle
{
	private:
		std::string			hash;
	public:
		static int			side_len;
		int					g;
		int					h;
		puzzle_config_t		map;
		Puzzle				*parent;

		Puzzle(const puzzle_config_t &v = {}) : g(0), h(0), map(v), parent(nullptr) {}
		Puzzle(std::initializer_list<int> l) : Puzzle() { map = l; }

		const std::string&	get_hash();

		static void			set_side_len(int len) { side_len = len; }
		int					f() const { return h + g; }

};

#endif
