#include "a_star.h"

void    test_hemming(void)
{
    uint8_t cases[][9] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 0},
        {0, 3, 8, 7, 6, 5, 2, 4, 1},
        {1, 2, 5, 4, 3, 7, 6, 8, 0}
    };
    double  answers[] = {0, 9, 4};
    double  result;
    
    for (int i = 0; i < 3; ++i)
        if ((result = hemming(cases[i], 3)) != answers[i])
            printf("FAIL hemming test %d, exp: %f, got: %f\n", i, answers[i], result);
}

void    test_manhattan(void)
{
    uint8_t cases[][9] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 0},
        {1, 2, 3, 0, 8, 7, 5, 6, 4},
        {0, 8, 7, 6, 5, 4, 3, 2, 1}
    };
    double  answers[] = {0, 14, 24};
    double  result;
    
    for (int i = 0; i < 3; ++i)
        if ((result = manhattan(cases[i], 3)) != answers[i])
            printf("FAIL manhattan test %d, exp: %f, got: %f\n", i, answers[i], result);
}

int main(void)
{
    test_hemming();
    test_manhattan();
    return (0);
}