#include "Puzzle.hpp"

int				Puzzle::side_len;

__uint128_t		Puzzle::get_hash() const // максимум для паззла из 16
{
	if (hash)
		return (hash);

	__uint128_t	out = 0;

	for (const auto &elem: map)
	{
		out += elem;
		out = (out << 4);
	}
	return (out);
}