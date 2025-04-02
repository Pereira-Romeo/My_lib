/*
** EPITECH PROJECT, 2024
** my_str_isprintable
** File description:
** returns 1 if is printable, 0 otherwise
*/

#include "../headers/my_str.h"
#include "../headers/my_bool.h"

int my_str_isprint(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 33 || str[i] > 126)
            return FALSE;
    }
    return TRUE;
}

int my_char_isprint(char const c)
{
    if (c < 33 || c > 126)
        return FALSE;
    return TRUE;
}

int my_char_isfence(char const c)
{
    if (my_char_isalpha(c) || my_char_isnumer(c))
        return FALSE;
    return TRUE;
}
