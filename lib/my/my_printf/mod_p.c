/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** mod_p
*/

#include "../headers/my_printf.h"

int get_ptr_hexa(char buffer[], unsigned long long int nb, char *chars)
{
    int len = 0;
    int reader = 0xF;

    for (int i = sizeof(long long int) * 2; i > 0; i--) {
        buffer[i] = chars[nb & reader];
        nb >>= 4;
        if (!nb)
            break;
        len++;
    }
    return sizeof(long long int) * 2 - len;
}

int mod_p(va_list list, fspe_t *pf)
{
    char buffer[] = "00000000000000000";
    char *ptr = buffer;
    long long int nb = (long long int) va_arg(list, void *);
    int len = 0;

    ptr += get_ptr_hexa(buffer, nb, BASE_CHARS);
    len += pf_width_handler(2 + my_strlen(ptr), pf);
    len += write(pf->fd, "0x", 2);
    len += zero_padding(my_strlen(ptr), pf);
    len += write(pf->fd, ptr, my_strlen(ptr));
    return len;
}
