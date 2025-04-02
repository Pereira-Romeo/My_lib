/*
** EPITECH PROJECT, 2025
** My_lib
** File description:
** my_is_in
*/

#include "../headers/my_str.h"

int my_char_is_in(char c, char *str)
{
    if (str == NULL)
        return 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return TRUE;
    return FALSE;
}

int my_str_isalnum_and(char *str, char *specials)
{
    for (char *ptr = str; *ptr != '\0'; ptr++)
        if (!my_char_isalnum(*ptr) && !my_char_is_in(*ptr, specials))
            return FALSE;
    return TRUE;
}
