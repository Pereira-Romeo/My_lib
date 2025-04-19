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
    my_printf("-99 is numer, negatives included: %d\n"
    "-99 is numer, negatives not inlcuded: %d\n",
    my_str_isnumer("-99", TRUE), my_str_isnumer("-99", FALSE));
    return 0;
}
