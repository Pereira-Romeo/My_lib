/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** mod_c
*/

#include "../headers/my_printf.h"

int mod_c(va_list list, fspe_t *pf)
{
    unsigned char c = va_arg(list, unsigned int);
    int len = 0;

    if (!(pf->flags & 4))
        len += pf_width_handler(1, pf);
    len += write(pf->fd, &c, 1);
    if (pf->flags & 4)
        len += pf_width_handler(1, pf);
    return len;
}
