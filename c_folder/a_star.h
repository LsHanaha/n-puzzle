#ifndef A_STAR_H
# define A_STAR_H

#include <stdint.h>
#include "libft.h"
#include <stdio.h>

typedef struct s_vizited_node
{
    uint8_t *map;
    uint8_t *from;
    double  g;
}               t_vizited_node;

uint8_t *a_star(uint8_t *map, uint8_t *goal, uint32_t side_len, double (*h)(uint8_t *map, uint8_t *goal, uint32_t side_len));
/*
    g = 0
    h = h(map)
    queue = rbt
    visited = rbt
    while (h(map, goal, side_len) != 0)
    {

    }

*/

double hemming(uint8_t *map, uint8_t *goal, uint32_t side_len);
/*
 [ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16]
*/

#endif