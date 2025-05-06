/*
** EPITECH PROJECT, 2025
** my_lib_new_printf
** File description:
** mod_s
*/

#include "../headers/my_printf.h"

int pf_putstr(char *str, fspe_t *pf)
{
    int str_len = 0;
    int real_len = 0;

    if (!str)
        str = "(nil)";
    if (pf->precision > 0)
        str_len = my_min(my_strlen(str), pf->precision);
    else
        str_len = my_strlen(str);
    if (!(pf->flags & 4))
        real_len += pf_width_handler(str_len, pf);
    real_len += write(pf->fd, str, str_len);
    if (pf->flags & 4)
        real_len += pf_width_handler(str_len, pf);
    return real_len;
}

int mod_s(va_list list, fspe_t *pf)
{
    char *str = va_arg(list, char *);

    return pf_putstr(str, pf);
}

int mod_big_s(va_list list, fspe_t *pf)
{
    char **str_list = va_arg(list, char **);
    char separator = (pf->flags & 8) ? ' ' : '\n';
    int len = 0;

    while (*str_list) {
        len += pf_putstr(*str_list, pf);
        len += write(pf->fd, &separator, 1);
        str_list++;
    }
    return len;
}
