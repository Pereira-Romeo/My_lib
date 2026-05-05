/*
** EPITECH PROJECT, 2025
** minishell1.2
** File description:
** my_strdupcat
*/

#include "../headers/my_str.h"
#include "../headers/my_mem.h"

char *strdupcat(char *s1, char *s2)
{
    char *str = NULL;

    if (!s1 && !s2)
        return NULL;
    if (s1 == NULL)
        return my_strdup(s2);
    if (s2 == NULL)
        return my_strdup(s1);
    str = my_calloc(my_strlen(s1) + my_strlen(s2) + 1, sizeof(char));
    if (str == NULL)
        return NULL;
    my_strcpy(str, s1);
    my_strcat(str, s2);
    return str;
}

char *strdup2cat(char *s1, char *s2, char *s3)
{
    char *str = NULL;

    if (s1 != NULL && s2 != NULL && s3 != NULL)
        str = my_calloc(my_strlen(s1) + my_strlen(s2) + my_strlen(s3) + 1,
            sizeof(char));
    if (str == NULL)
        return NULL;
    my_strcpy(str, s1);
    my_strcat(str, s2);
    my_strcat(str, s3);
    return str;
}

char *strdupncat(char *s1, char *s2, int n)
{
    char tmp[my_strlen(s2)];

    my_strncpy(tmp, s2, n);
    return strdupcat(s1, tmp);
}
