/*
** EPITECH PROJECT, 2025
** my_lib
** File description:
** my_printf
*/

#include "../headers/my_printf.h"
#include <stdio.h>

static
const spe_t spe_tab[] =
{
    {'d', &mod_d}, //int, long int, long long int
    {'s', &mod_s}, //string
    {'x', &mod_x}, //unsigned hexadecimal conversion
    {'X', &mod_big_x}, //unsigned HEXADECIMAL conversion
    {'S', &mod_big_s}, //list of string
    {'b', &mod_b}, //unsigned binary conversion
    {'f', &mod_f}, //double
    {'p', &mod_p}, //pointer
    {'c', &mod_c}, //unsigned char
    {'i', NULL}, //int, long int, long long int
    {'F', NULL}, //double
    {'u', NULL}, //unsigned decimal conversion
    {'a', NULL}, //double in hexadecimal
    {'A', NULL}, //double in HEXADECIMAL
    {'e', NULL}, //double in scientific
    {'E', NULL}, //double in SCIENTIFIC
    {'%', NULL}, //%
    {'o', NULL}, //unsigned octal conversion
    {'g', NULL}, //double, chosen btw e and f
    {'G', NULL}, //double, chosen btew E and F
    {'n', NULL}, //int *, store characters written so far
    {'\0', NULL}
};

//finds c inside str and puts it's index in index
//if c wasn't found, str[index] will be the end of the str
static
int pf_is_in(char c, char *str, int *index)
{
    int i = 0;

    if (!str)
        return FALSE;
    for (; str[i]; i++) {
        if (str[i] == c) {
            *index = i;
            return TRUE;
        }
    }
    *index = i;
    return FALSE;
}

static
int print_segment(char **ptr, int i, fspe_t *pf)
{
    int len = 0;

    if (!(**ptr))
        return pf->current_len;
    len = write(pf->fd, *ptr, i);
    if (len == -1)
        return -1;
    *ptr += i + 1;
    pf->current_len += len;
    return pf->current_len;
}

//should add up length to current_len
//printf("\e[1;33mptr after filling:\e[0m %s\n", *ptr);
static
int print_mod(char **ptr, int i, va_list list, fspe_t *pf)
{
    int len = 0;

    if (print_segment(ptr, i, pf) == -1)
        return -1;
    make_fspe_mod(pf, ptr, list);
    if (!(**ptr))
        return 0;
    for (int i = 0; spe_tab[i].func; i++) {
        if (spe_tab[i].letter == **ptr)
            len = spe_tab[i].func(list, pf);
    }
    if (len == -1)
        my_lperror("my_printf", -1);
    (*ptr)++;
    pf->current_len += len;
    return 0;
}

//if using c_is_in, this loop needs to be updated to be optimised
int printf_loop(char *format, va_list list, fspe_t *pf)
{
    char *ptr = format;
    int index = 0;
    int val = 0;

    while (*ptr) {
        if (pf_is_in('%', ptr, &index)) {
            val = print_mod(&ptr, index, list, pf);
            reset_pf(pf);
        } else {
            break;
        }
        if (val == -1)
            break;
    }
    return print_segment(&ptr, index, pf);
}

int my_printf(char *format, ...)
{
    fspe_t pf = {STDOUT_FILENO, 0, -1, -1, 0, 0};
    int len = 0;
    va_list list;

    if (format == NULL)
        return 0;
    va_start(list, format);
    len = printf_loop(format, list, &pf);
    va_end(list);
    return len;
}

int my_dprintf(int fd, char *format, ...)
{
    fspe_t pf = {fd, 0, 0, 0, 0, 0};
    int len = 0;
    va_list list;

    if (fd < 0)
        return my_lputerr("my_dprintf", EBADF, -1);
    if (format == NULL)
        return 0;
    va_start(list, format);
    len = printf_loop(format, list, &pf);
    va_end(list);
    return len;
}
