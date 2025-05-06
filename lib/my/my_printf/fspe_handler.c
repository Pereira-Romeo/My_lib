/*
** EPITECH PROJECT, 2025
** my_lib_off
** File description:
** fspe_maker
*/

#include "../headers/my_printf.h"

static
int my_c_isnum(char const c)
{
    if (c < 48 || c > 57)
        return FALSE;
    return TRUE;
}

void reset_pf(fspe_t *pf)
{
    pf->flags = 0;
    pf->len_mod = 0;
    pf->precision = -1;
    pf->width = 0;
}

static
int add_len_mod(char flag, fspe_t *mod)
{
    if (flag == 'l') {
        mod->len_mod |= (mod->len_mod & 1) ? 2 : 1;
        return TRUE;
    }
    if (flag == 'h') {
        mod->len_mod |= (mod->len_mod & 4) ? 8 : 4;
        return TRUE;
    }
    return FALSE;
}

static
int add_flags(char flag, fspe_t *mod)
{
    switch (flag) {
    case '#':
        mod->flags |= 1;
        return TRUE;
    case '0':
        mod->flags |= 2;
        return TRUE;
    case '-':
        mod->flags |= 4;
        return TRUE;
    case ' ':
        mod->flags |= 8;
        return TRUE;
    case '+':
        mod->flags |= 16;
        return TRUE;
    default:
        return FALSE;
    }
}

static
void add_precision(fspe_t *pf, char **ptr, va_list list)
{
    (*ptr)++;
    if (!my_char_isnumer(**ptr) && **ptr != '*')
        return;
    if (**ptr == '*') {
        pf->precision = va_arg(list, int);
        (*ptr)++;
    } else {
        pf->precision = my_getnbr(*ptr);
        while (my_c_isnum(**ptr))
            (*ptr)++;
    }
}

static
void add_wp(fspe_t *pf, char **ptr, va_list list)
{
    if (**ptr == '*') {
        pf->width = va_arg(list, int);
        (*ptr)++;
    } else {
        pf->width = my_getnbr(*ptr);
        while (my_c_isnum(**ptr))
            (*ptr)++;
    }
    if (**ptr == '.') {
        add_precision(pf, ptr, list);
    }
}

void make_fspe_mod(fspe_t *pf, char **ptr, va_list list)
{
    for (; **ptr; *ptr += 1) {
        if (add_flags(**ptr, pf))
            continue;
        break;
    }
    add_wp(pf, ptr, list);
    for (; **ptr; *ptr += 1) {
        if (add_len_mod(**ptr, pf))
            continue;
        break;
    }
}
