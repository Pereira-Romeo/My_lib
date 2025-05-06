/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** mod_x
*/

#include "../headers/my_printf.h"

int get_hexa(char buffer[9], unsigned int nb, char *chars)
{
    int len = 0;
    int reader = 0xF;

    for (int i = 8; i > 0; i--) {
        buffer[i] = chars[nb & reader];
        nb >>= 4;
        if (!nb)
            break;
        len++;
    }
    return 8 - len;
}

int mod_x(va_list list, fspe_t *pf)
{
    char buffer[] = "00000000";
    char *ptr = buffer;
    unsigned int nb = va_arg(list, unsigned int);
    int flag1 = (pf->flags & 1) ? 2 : 0;
    int len = 0;

    ptr += get_hexa(buffer, nb, BASE_CHARS);
    len += pf_width_handler(flag1 + my_strlen(ptr), pf);
    if (pf->flags & 1)
        len += write(pf->fd, "0x", 2);
    len += zero_padding(my_strlen(ptr), pf);
    len += write(pf->fd, ptr, my_strlen(ptr));
    return len;
}

int mod_big_x(va_list list, fspe_t *pf)
{
    char buffer[] = "00000000";
    char *ptr = buffer;
    unsigned int nb = va_arg(list, unsigned int);
    int flag1 = (pf->flags & 1) ? 2 : 0;
    int len = 0;

    ptr += get_hexa(buffer, nb, M_BASE_CHARS);
    len += pf_width_handler(flag1 + my_strlen(ptr), pf);
    if (pf->flags & 1)
        len += write(pf->fd, "0X", 2);
    len += zero_padding(my_strlen(ptr), pf);
    len += write(pf->fd, ptr, my_strlen(ptr));
    return len;
}
