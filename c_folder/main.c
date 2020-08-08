#include "a_star.h"

int main()
{
    uint8_t mymap[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    uint8_t goal[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0}; // DEPRECATED; will now always be sorted mymap (except for zero)
    a_star(mymap, 4, hemming);
    return (0);
}