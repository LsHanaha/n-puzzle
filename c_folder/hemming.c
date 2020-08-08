    /*
        1 2 3       1 2 3       0 0 0
        4 5 6       9 8 7   ->  1 1 1
        7 8 9       5 6 4       1 1 1
    */
   

#include "a_star.h"

double hemming(uint8_t *map, uint8_t *goal, uint32_t side_len)
{
    double  out;

    out = 0;
    for (int i = 0; i < side_len * side_len; ++i)
        if (map[i])
            out += (map[i] != (i + 1));
        else
            out += ((i + 1) != (side_len * side_len));
    return (out);
}