/*
** EPITECH PROJECT, 2025
** my_lib_off
** File description:
** my_nb_occ
*/

#include "../headers/my_str.h"

int my_nb_occ(char *str, char c)
{
    int occ = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            occ++;
    }
    return occ;
}
