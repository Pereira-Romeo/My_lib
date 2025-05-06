/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** mod_b
*/

#include "../headers/my_printf.h"

int bin_presicion_padding(int length, fspe_t *pf)
{
    int len = 0;

    for (int i = pf->precision; i > length; i--) {
        if (i % 5 == 0 && pf->flags & 8) {
            len += (i < pf->precision) ? write(pf->fd, " ", 1) : 0;
            i--;
        }
        len += write(pf->fd, "0", 1);
    }
    return len;
}

int get_binary(char *buffer, int val, fspe_t *pf)
{
    unsigned int reader = 0b1;

    for (unsigned int i = 0; i < BITS_INT + 7; i++) {
        if ((i + 1) % 5 == 0 && i > 0 && pf->flags & 8)
            i++;
        buffer[BITS_INT + 6 - i] = (val & reader) ? '1' : '0';
        val >>= 1;
        if (!val)
            return BITS_INT + 6 - i;
    }
    return BITS_INT + 6;
}

int mod_b(va_list list, fspe_t *pf)
{
    char buffer[] = "0000 0000 0000 0000 0000 0000 0000 0000";
    char *ptr = buffer;
    unsigned int nb = va_arg(list, unsigned int);
    int flag1 = (pf->flags & 1) ? 2 : 0;
    int ptr_len = 0;
    int len = 0;

    ptr += get_binary(buffer, nb, pf);
    ptr_len = my_strlen(ptr);
    pf->precision += (pf->flags & 8) ? pf->precision / 4 : 0;
    len += pf_width_handler(flag1 + my_max(ptr_len, pf->precision), pf);
    if (pf->flags & 1)
        len += write(pf->fd, "0b", 2);
    len += bin_presicion_padding(my_strlen(ptr), pf);
    len += write(pf->fd, ptr, my_strlen(ptr));
    return len;
}
