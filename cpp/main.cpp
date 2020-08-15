#include "n_puzzle.hpp"
#include <iostream>


int	main(void)
{
	//Puzzle *test = new Puzzle({4, 0, 8, 2, 10, 12, 5, 7, 13, 9, 3, 14, 15,11, 6, 1});
	Puzzle *test = new Puzzle({3, 5, 1, 12, 0, 15, 2, 7, 14, 11, 9, 13, 8, 6, 10, 4});
	//Puzzle *test = new Puzzle({4, 3, 9, 14, 2, 13, 7, 11, 5, 0, 6, 12, 15, 8, 1, 10});
	Puzzle::set_side_len(4);
	std::string result = a_star(test, phased_manhattan);
	std::cout << result << std::endl;
	return (0);
}

// комплировать g++ -std=c++11 *.cpp
// опционально -g / -O