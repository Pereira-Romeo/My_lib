/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** nullify tab
*/

#include "../headers/my_tab.h"
#include <stdlib.h>

int str_tabnullify(char **tab, int free_them)
{
    if (!tab)
        return -1;
    for (int i = 0; tab[i]; i++) {
        if (free_them)
            free(tab[i]);
        tab[i] = NULL;
    }
    return 0;
}
