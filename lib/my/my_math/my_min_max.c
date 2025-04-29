/*
** EPITECH PROJECT, 2025
** my_lib_off
** File description:
** my_min_max
*/

#include "../headers/my_math.h"

int my_min(int n1, int n2)
{
    return (n1 < n2) ? n1 : n2;
}

int my_max(int n1, int n2)
{
    return (n1 < n2) ? n2 : n1;
}
