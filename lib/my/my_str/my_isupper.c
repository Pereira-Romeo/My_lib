/*
** EPITECH PROJECT, 2024
** my_str_isupper
** File description:
** returns 1 if is upper case alphabet, 0 otherwise
*/

#include "../headers/my_bool.h"

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 65 || str[i] > 90)
            return FALSE;
    }
    return TRUE;
}

int my_char_isupper(char const c)
{
    if (c < 65 || c > 90)
        return FALSE;
    return TRUE;
}
