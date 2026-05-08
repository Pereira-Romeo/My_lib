/*
** EPITECH PROJECT, 2024
** task 01 - my_strcpy
** File description:
** 3 funcs to copy src into dest
*/

#include "../headers/my_str.h"
#include <stddef.h>

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strncpy(char *dest, char *src, int n)
{
    if (n < 0)
        return 0;
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
    dest[n] = '\0';
    return dest;
}

char *mstrn_to_mcpy(char *dest, char *src, int n, int m)
{
    int dest_i = 0;

    if (n < 0 || n >= my_strlen(src))
        return NULL;
    for (int i = n; i <= m; i++) {
        dest[dest_i] = src[i];
        dest_i++;
    }
    dest[m - n + 1] = '\0';
    return dest;
}

char *mstrn_to_ccpy(char *dest, char *src, int n, char c)
{
    int dest_i = 0;
    int i = n;

    if (n < 0 || n > my_strlen(src))
        return NULL;
    for (; src[i] != '\0'; i++) {
        if (src[i] == c)
            break;
        dest[dest_i] = src[i];
        dest_i++;
    }
    dest[i - n + 1] = '\0';
    return dest;
}

char *my_strcpy_from(char *dest, char *src, int n)
{
    int i = 0;

    while (src[n] != '\0') {
        dest[i] = src[n];
        n++;
        i++;
    }
    dest[i] = '\0';
    return dest;
}
