/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** 3 funcs to display numbers
*/

#include "../headers/my_str.h"

int my_putlli(long long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb < 10) {
        my_putchar((nb % 10) + 48);
    } else {
        my_putlli(nb / 10);
        my_putlli(nb % 10);
    }
    return my_count_lli(nb);
}

int my_putint(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb < 10) {
        my_putchar((nb % 10) + 48);
    } else {
        my_putint(nb / 10);
        my_putint(nb % 10);
    }
    return my_count_int(nb);
}

//should move my_fnber to my_printf/
int my_fnbr(int width, int nb)
{
    int len = 0;

    len += padding(my_count_int(nb), width);
    len += my_put_int(nb);
    return len;
}
