/*
** EPITECH PROJECT, 2024
** main
** File description:
** testing the library
*/

#include "my.h"
#include <math.h>

int main(void)
{
    double sqrt_res = 0;
    double my_res = 0;

    for (int i = 2; i < 5000; i++) {
        printf("on loop: %d\n", i);
        sqrt_res = sqrt(i);
        my_res = my_sqrt(i);
        if (sqrt_res == my_res)
            printf("\e[1;32mSquare root is equal\n"
            "%f == %f\e[0m\n", sqrt_res, my_res);
        else
            printf("\e[1;31mSquare root is different\n"
            "%f != %f\e[0m\n", sqrt_res, my_res);
    }
    return 0;
}
