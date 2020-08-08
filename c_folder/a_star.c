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


uint8_t *cook_new_map(uint8_t *map, int zero, int new_place, int map_size)
{
    uint8_t temp;
    uint8_t *new_map;

    new_map = (uint8_t *)malloc(map_size);
    ft_memmove(new_map, map, map_size);

    temp = new_map[zero];
    new_map[zero] = new_map[new_place];
    new_map[new_place] = temp;

    return new_map;
}


uint8_t **neighbours(uint8_t *map, int side_len)
{
    /*
        top, left, right, bottom
    */
    int zero_id = 0;
    int map_size;
    uint8_t **result;

    map_size = side_len * side_len;
    result = (uint8_t **)ft_memalloc(4 * sizeof(uint8_t *));

    for (; zero_id < map_size; ++zero_id)
        if (!map[zero_id])
            break;

    if (zero_id - side_len >= 0)
        result[0] = cook_new_map(map, zero_id, zero_id - side_len, map_size);
    if (zero_id % side_len - 1 >= 0)
        result[1] = cook_new_map(map, zero_id, zero_id - 1, map_size);
    if (zero_id % side_len + 1 < side_len)
        result[2] = cook_new_map(map, zero_id, zero_id + 1, map_size);
    if (zero_id + side_len < map_size)    
        result[3] = cook_new_map(map, zero_id, zero_id + side_len, map_size);
    for (int j = 0; j < 4; j++)
    {
        char ways[4][10] = {"top", "left", "right", "bottom"};
        if (result[j])
        {
            printf("%s:\n", ways[j]);
            print_map(result[j], side_len);
        }
        printf("\n");
    }
    return result;
}


uint8_t *a_star(uint8_t *map, int side_len, double (*euristic)(uint8_t *map, int side_len))
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
    uint8_t **neighb;


    printf("map:\n");
    print_map(map, side_len);

    g = 0;
    // while (euristic(map, goal, side_len))
    while(1)
    {
        neighb = neighbours(map, side_len);
        for (int i = 0; i < 4; i++)
        {
            if (neighb[i])
            {
                h = euristic(neighb[i], side_len);
                printf("h = %f\n", h);
            }    
        }
        break;
    }
    
    return 1;
}


