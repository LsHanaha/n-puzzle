#include "n_puzzle.h"

int	main(void)
{
	Puzzle *test = new Puzzle({4, 0, 8, 2, 10, 12, 5, 7, 13, 9, 3, 14, 15,11, 6, 1});
	//Puzzle *test = new Puzzle({4, 3, 9, 14, 2, 13, 7, 11, 5, 0, 6, 12, 15, 8, 1, 10});
	Puzzle::set_side_len(4);
	Puzzle *result = a_star(test, phased_manhattan);
	for (const auto &v: result->map)
		std::cout << v << " ";
	std::cout << "\n";
	return (0);
}

// комплировать g++ -std=c++11 *.cpp
// опционально -g / -O