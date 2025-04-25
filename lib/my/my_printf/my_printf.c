/*
** EPITECH PROJECT, 2024
** my_printf.c
** File description:
** .
*/

#include <stdarg.h>
#include <stddef.h>
#include "../headers/my.h"

static const sflag_t flag_tab[8] =
{
    {'d', &my_fnbr},
    {'i', &my_fnbr},
    {'c', &my_fchar},
    {'x', &mod_x},
    {'X', &mod_x_maj},
    {'o', &mod_o},
    {'u', &mod_u},
    {'\0', NULL}
};

static int my_char_ispecifier(char c)
{
    char *specifier_list = "sn%dicxXoefEFpug";

    for (int i = 0; specifier_list[i] != '\0'; i++) {
        if (c == specifier_list[i])
            return 1;
    }
    return 0;
}

static int find_specifier(char *format, int i)
{
    int j = i;

    for (; j < my_strlen(format); j++) {
        if (my_char_ispecifier(format[j]) == 1)
            break;
    }
    return j;
}

int spe_flag_manager(char *format, int i, va_list list, int width)
{
    int len = 0;
    int i_end = find_specifier(format, i);

    if (format[i_end] == '%')
        len += my_putchar('%');
    if (format[i_end] == 's')
        len += my_fstr(width, va_arg(list, char *));
    if (format[i_end] == 'n')
        *va_arg(list, int *) = len;
    if (format[i_end] == 'f' || format[i_end] == 'F')
        len += mod_f_maj_f(width, va_arg(list, double), 6);
    if (format[i_end] == 'e' || format[i_end] == 'E')
        len += mod_e_maj_e(width, va_arg(list, double), 6);
    if (format[i_end] == 'p')
        len += mod_p(width, va_arg(list, void *));
    if (format[i_end] == 'g')
        len += mod_g(width, va_arg(list, double), 6);
    return len;
}

int flag_manager(char *format, int i, va_list list, int len)
{
    int i_end = find_specifier(format, i);
    int width = width_manager(format, i, list);
    int not_int_flag = len + spe_flag_manager(format, i, list, width);

    if (not_int_flag > len)
        return not_int_flag;
    for (int j = 0; flag_tab[j].letter != '\0'; j++) {
        if (flag_tab[j].letter == format[i_end])
            len += flag_tab[j].func_of(width,
            va_arg(list, int));
    }
    if (len == not_int_flag)
        len += my_putstr_i_end(format, i + 1, i_end);
    return len;
}

int my_printf(char *format, ...)
{
    va_list list;
    int count = 0;

    va_start(list, format);
    if (format == NULL)
        return 84;
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            count = flag_manager(format, i, list, count);
            i = find_specifier(format, i);
        } else {
            my_putchar(format[i]);
            count++;
        }
    }
    va_end(list);
    return count;
}
