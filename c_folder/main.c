#include "a_star.h"

int main()
{
    uint8_t mymap[] = {10,  9, 14,  1,  4  ,8, 12,  5,  3,  2,  6, 11,  0,  7, 15, 13};
    uint8_t goal[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    a_star(mymap, goal, 4, NULL);
    return (0);
}