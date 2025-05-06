/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** lli_mod_d
*/

#include "../headers/my_printf.h"

int pf_putlli(long long int nb, fspe_t *pf)
{
    if (nb < 0) {
        write(pf->fd, "-", 1);
        nb *= -1;
    }
    if (nb < 10) {
        pf_putchar(nb % 10 + '0', pf);
    } else {
        pf_putlli(nb / 10, pf);
        pf_putlli(nb % 10, pf);
    }
    return my_llilen(nb);
}

int lli_mod_d(va_list list, fspe_t *pf)
{
    long long int nb = va_arg(list, long long int);
    int Tlen = my_max(my_llilen(nb), pf->precision);
    int len = 0;

    if (!(pf->flags & 4))
        len += pf_width_handler(Tlen, pf);
    if (nb < 0) {
        len += write(pf->fd, "-", 1);
        nb *= -1;
    } else {
        len += print_plus(pf);
    }
    len += zero_padding(my_llilen(nb), pf);
    if (nb != 0 || pf->precision != 0)
        len += pf_putlli(nb, pf);
    if (pf->flags & 4)
        len += pf_width_handler(Tlen, pf);
    return len;
}
