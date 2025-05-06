/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** precision_handler
*/

#include "../headers/my_printf.h"

int zero_padding(int length, fspe_t *pf)
{
    int len = 0;

    while (len < pf->precision - length)
        len += write(pf->fd, "0", 1);
    return len;
}
