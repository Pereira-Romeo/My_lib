/*
** EPITECH PROJECT, 2024
** My_lib
** File description:
** free_linked_list
*/

#include "../headers/my_linked_list.h"

void free_cell(linked_list_t *list, cell_t *cell)
{
    if (!list || !cell)
        return;
    if (cell->prev)
        cell->prev->next = cell->next;
    else
        list->head = cell->next;
    if (cell->next)
        cell->next->prev = cell->prev;
    else
        list->tail = cell->prev;
    free(cell);
}

void free_linked_list(linked_list_t *list)
{
    cell_t *current = NULL;
    cell_t *next = NULL;

    if (!list)
        return;
    current = list->head;
    while (current) {
        next = current->next;
        free_cell(list, current);
        current = next;
    }
    free(list);
}
