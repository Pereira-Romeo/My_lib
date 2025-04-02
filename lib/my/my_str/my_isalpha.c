/*
** EPITECH PROJECT, 2024
** verify if is only letters
** File description:
** returns 1 if str only has alphabetical characters
*/
#include "../headers/my_bool.h"

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 65 || str[i] > 122)
            return 0;
        if (str[i] > 90 && str[i] < 97)
            return FALSE;
    }
    return TRUE;
}

int my_char_isalpha(char const c)
{
    if (c < 65 || c > 122)
        return 0;
    if (c > 90 && c < 97)
        return FALSE;
    return TRUE;
}
