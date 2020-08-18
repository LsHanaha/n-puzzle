#include "Puzzle.hpp"

int					Puzzle::side_len;

const std::string&	Puzzle::get_hash()
{
	if (!hash.empty())
		return (hash);

	for (unsigned i = 0; i < map.size(); ++i)
	{
		if (i % 2 == 0)
			hash.push_back(0);
		else
			hash[i / 2] <<= 4;
		hash[i / 2] += map[i];
	}
	return (hash);
}
