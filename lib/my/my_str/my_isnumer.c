/*
** EPITECH PROJECT, 2024
** my_str_isnum
** File description:
** returns 1 if str is only numerical, 0 otherwise
*/

#include "../headers/my_bool.h"

int my_str_isnumer(char const *str, int include_negatives)
{
    int val = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        val = (include_negatives) ? str[i] != '-' : 1;
        if ((str[i] < 48 || str[i] > 57) && val)
            return FALSE;
    }
    return TRUE;
}

int my_char_isnumer(char const c)
{
    if (c < 48 || c > 57)
        return FALSE;
    return TRUE;
}
