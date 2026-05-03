/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** my_strdup
*/

#include "../headers/my_str.h"
#include "../headers/my_mem.h"

char *my_strdup(const char *src)
{
    char *dest = NULL;

    if (src == NULL)
        return NULL;
    dest = my_calloc(my_strlen(src) + 1, sizeof(char));
    if (dest == NULL)
        return NULL;
    my_strcpy(dest, src);
    return dest;
}

char *my_strdup_from(char *src, int n)
{
    char *dest = NULL;

    if (src == NULL)
        return NULL;
    dest = my_calloc(my_strlen(src) - n + 1, sizeof(char));
    if (dest == NULL)
        return NULL;
    my_strcpy_from(dest, src, n);
    return dest;
}

char *strdup_till(char *src, char c)
{
    char *dest = NULL;
    char *tmp = my_calloc(my_strlen(src) + 1, sizeof(char));
    int len = 0;

    if (tmp == NULL)
        return NULL;
    for (; src[len] != c && src[len] != '\0'; len++) {
        tmp[len] = src[len];
    }
    dest = my_calloc(len + 1, sizeof(char));
    if (dest != NULL)
        my_strcpy(dest, tmp);
    free(tmp);
    return dest;
}
