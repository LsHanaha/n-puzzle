    /*
        1 2 3       1 2 3       0 0 0
        4 5 6       9 8 7   ->  3 1 3  -> 14
        7 8 9       5 6 4       2 2 3
    */
   
#include "a_star.h"

struct s_point
{
    int x;
    int y;
};

double manhattan(uint8_t *map, int side_len)
{
    double          out;
    struct s_point  current;
    struct s_point  gold;
    int             gold_i;
    
    out = 0.0;
    for (int i = 0; i < side_len * side_len; ++i)
    {
        current.x = i / side_len;
        current.y = i % side_len;
        gold_i = (map[i] ? (map[i] - 1) : (side_len * side_len - 1));
        gold.x = gold_i / side_len;
        gold.y = gold_i % side_len;
        out += abs(gold.x - current.x) + abs(gold.y - current.y);
    }
    return (out);
}