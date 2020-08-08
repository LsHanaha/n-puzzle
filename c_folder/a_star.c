#include "a_star.h"

void    print_map(uint8_t *map, uint32_t side_len)
{
    for (uint32_t i = 0; i < side_len * side_len; ++i)
        {
            printf("%hhd ", map[i]);
            if (i % side_len == side_len - 1)
                printf("\n");
        }
    printf("\n");
}


void neighbours(uint8_t *map, uint32_t side_len)
{
    int zero_id = 0;
    int x, y;

    for (; zero_id < side_len * side_len; ++zero_id)
        if (!map[zero_id])
            break;
    printf("zero_id = %d\n", zero_id);
    x = zero_id / side_len;
    y = zero_id % side_len;

    printf("%d  %d\n", x, y);
    

            
    // map[i][i+1]
}




uint8_t *a_star(uint8_t *map, uint8_t *goal, uint32_t side_len, double (*euristic)(uint8_t *map, uint8_t *goal, uint32_t side_len))
{
   /*
    g = 0
    h = h(map)
    queue = rbt
    visited = rbt
    while (h(map, goal, side_len) != 0)
    {
        
    }

*/
    double  g = 0.0;
    double  h = 0.0;
    t_rbt   *queue = NULL;
    t_rbt   *visited = NULL;

    printf("map:\n");
    print_map(map, side_len);
    printf("goal:\n");
    print_map(goal, side_len);

    g = 0;
    // while (euristic(map, goal, side_len))
    while(1)
    {
        uint8_t neigb[] = {NULL, NULL, NULL, NULL}; 
        neighbours(map, side_len);
        break;
    }
    
    return 1;
}


