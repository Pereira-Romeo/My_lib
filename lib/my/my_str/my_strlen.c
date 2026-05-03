/*
** EPITECH PROJECT, 2024
** d03 - my_strlen
** File description:
** counts the number of chars in a str and returns it
*/

#include <stddef.h>

static int c_is_in(char c, char *str)
{
    if (str == NULL)
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

int my_strlen(const char *str)
{
    const char *ptr = str;

    while (ptr && *ptr) {
        ptr++;
    }
    return ptr - str;
}

int mstrn_to_clen(char *str, int n, char *c)
{
    int i = 0;

    if (str == NULL)
        return 0;
    if (n < 0 || n > my_strlen(str))
        return -1;
    while (str[n + i] != '\0') {
        if (c_is_in(str[n + i], c))
            break;
        i++;
    }
    return i;
}
