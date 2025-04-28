/*
** EPITECH PROJECT, 2024
** My_lib
** File description:
** add_to_linked_list
*/

#include <unistd.h>
#include "../headers/my_linked_list.h"

linked_list_t *init_linked_list(void)
{
    linked_list_t *list = my_calloc(1, sizeof(linked_list_t));

    if (list == NULL)
        return NULL;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

static cell_t *make_cell(cell_t *prev, void *data, cell_t *next)
{
    cell_t *cell = my_calloc(1, sizeof(cell_t));

    if (cell == NULL)
        return NULL;
    cell->prev = prev;
    cell->data = data;
    cell->next = next;
    return cell;
}

linked_list_t *add_as_head(linked_list_t *list, void *data)
{
    cell_t *cell = NULL;

    if (list->head == NULL) {
        cell = make_cell(NULL, data, NULL);
        if (cell == NULL)
            return NULL;
        list->head = cell;
        list->tail = cell;
    } else {
        list->head->prev = make_cell(NULL, data, list->head);
        if (list->head->prev == NULL)
            return NULL;
        list->head = list->head->prev;
    }
    return list;
}

linked_list_t *add_as_tail(linked_list_t *list, void *data)
{
    cell_t *cell = NULL;

    if (list->tail == NULL) {
        cell = make_cell(NULL, data, NULL);
        if (cell == NULL)
            return NULL;
        list->head = cell;
        list->tail = cell;
    } else {
        list->tail->next = make_cell(list->tail, data, NULL);
        if (list->tail->next == NULL)
            return NULL;
        list->tail = list->tail->next;
    }
    return list;
}
