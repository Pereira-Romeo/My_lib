/*
** EPITECH PROJECT, 2025
** my_lib
** File description:
** my_tabdup
*/

#include "../headers/my_tab.h"
#include "../headers/my_mem.h"
#include "../headers/my_str.h"

char **str_tabdup(char **tab)
{
    int len = str_tablen(tab);
    char **new_tab = my_calloc(len + 1, sizeof(char *));

    if (new_tab == NULL)
        return NULL;
    for (int i = 0; tab[i] != NULL; i++) {
        new_tab[i] = my_strdup(tab[i]);
        if (new_tab[i] == NULL)
            return free_strtab(new_tab);
    }
    return new_tab;
}
