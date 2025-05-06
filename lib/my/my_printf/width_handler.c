/*
** EPITECH PROJECT, 2025
** my_lib_new_printf
** File description:
** width_handler
*/

#include "../headers/my_printf.h"

int pf_width_handler(int length, fspe_t *pf)
{
    char c = (pf->flags & 2) ? '0' : ' ';
    int len = 0;

    while (len < pf->width - length)
        len += write(pf->fd, &c, 1);
    return len;
}
