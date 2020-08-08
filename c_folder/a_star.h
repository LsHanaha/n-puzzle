#ifndef A_STAR_H
# define A_STAR_H

#include <stdint.h>
#include "libft.h"
#include <stdio.h>

typedef struct s_vizited_node
{
	double  f;
    uint8_t *map;
    uint8_t *from;
}               t_vizited_node;

typedef struct s_queue_elem
{
	double  f;
    uint8_t *map;
}              t_queue_elem;

uint8_t *a_star(uint8_t *map, int side_len, double (*h)(uint8_t *map, int side_len));
/*
    g = 0
    h = h(map)
    queue = rbt
    visited = rbt
    while (h(map, goal, side_len) != 0)
    {

    }

*/

double hemming(uint8_t *map, int side_len);
double manhattan(uint8_t *map, int side_len);
/*
 [ 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16]
*/

#endif