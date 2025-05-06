/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** mod_f
*/

#include "../headers/my_printf.h"

int round_my_nb(int nb)
{
    for (int i = 0; i < 5; i++) {
        if (nb % 10 >= 5)
            nb++;
    }
    return nb;
}

int precision_filler(int depth, fspe_t *pf)
{
    int len = 0;

    while (len < depth) {
        len += write(pf->fd, "0", 1);
    }
    return len;
}

int mod_f(va_list list, fspe_t *pf)
{
    double nb = va_arg(list, double);
    int w_nb = (int) nb;
    int depth = (pf->precision > -1) ? pf->precision : 6;
    int q_nb = round_my_nb((nb - w_nb) * my_power(10, depth + 1)) / 10;
    int d_point = (pf->precision != 0 || pf->flags & 1) ? 1 : 0;
    int Tlen = my_intlen(w_nb) + d_point + depth;
    int len = 0;

    if (!(pf->flags & 4))
        len += pf_width_handler(Tlen, pf);
    len += pf_putint(w_nb, pf);
    if (d_point)
        len += write(pf->fd, ".", 1);
    if (depth)
        len += (q_nb != 0) ? pf_putint(q_nb, pf) : precision_filler(depth, pf);
    if (pf->flags & 4)
        len += pf_width_handler(Tlen, pf);
    return len;
}
