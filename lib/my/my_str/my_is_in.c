/*
** EPITECH PROJECT, 2025
** My_lib
** File description:
** my_is_in
*/

#include "../headers/my_str.h"

int my_char_is_in(char c, char *str, int *index)
{
    int tmp = 0;
    int i = 0;

    if (!index)
        index = &tmp;
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

int one_c_is_in(char *c, char *str, int *str_index, int *c_index)
{
    int tmp = 0;
    int c_tmp = 0;
    int i = 0;

    if (!str_index)
        str_index = &tmp;
    if (!c_index)
        c_index = &c_tmp;
    if (!str)
        return FALSE;
    for (; str[i]; i++) {
        if (my_char_is_in(str[i], c, c_index)) {
            *str_index = i;
            return TRUE;
        }
    }
    *str_index = i;
    return FALSE;
}

int my_str_isalnum_and(char *str, char *specials)
{
    for (char *ptr = str; *ptr != '\0'; ptr++)
        if (!my_char_isalnum(*ptr) && !my_char_is_in(*ptr, specials, NULL))
            return FALSE;
    return TRUE;
}
