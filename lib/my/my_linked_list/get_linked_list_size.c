/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** get_linked_list_size
*/

#include "../headers/my_linked_list.h"

int get_linked_list_size(linked_list_t *list)
{
    cell_t *cell = NULL;
    int i = 0;

    if (!list)
        return 0;
    if (list->head == NULL)
        return 0;
    cell = list->head;
    while (cell != NULL) {
        i++;
        cell = cell->next;
    }
    return i;
}
