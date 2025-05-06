/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** lgi_mod_d
*/

#include "../headers/my_printf.h"

int pf_putlgi(long int nb, fspe_t *pf)
{
    if (nb < 0) {
        write(pf->fd, "-", 1);
        nb *= -1;
    }
    if (nb < 10) {
        pf_putchar(nb % 10 + '0', pf);
    } else {
        pf_putlgi(nb / 10, pf);
        pf_putlgi(nb % 10, pf);
    }
    return my_lgilen(nb);
}

int long_mod_d(va_list list, fspe_t *pf)
{
    long int nb = va_arg(list, long int);
    int Tlen = my_max(my_lgilen(nb), pf->precision);
    int len = 0;

    if (!(pf->flags & 4))
        len += pf_width_handler(Tlen, pf);
    if (nb < 0) {
        len += write(pf->fd, "-", 1);
        nb *= -1;
    } else {
        len += print_plus(pf);
    }
    len += zero_padding(my_lgilen(nb), pf);
    if (nb != 0 || pf->precision != 0)
        len += pf_putlgi(nb, pf);
    if (pf->flags & 4)
        len += pf_width_handler(Tlen, pf);
    return len;
}
