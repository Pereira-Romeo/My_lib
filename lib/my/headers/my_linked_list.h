/*
** EPITECH PROJECT, 2024
** my_linked_list.h
** File description:
** my linked list lib
*/

#ifndef MY_LINKED_LIST_H
    #define MY_LINKED_LIST_H
    #include <stddef.h>
    #include <stdlib.h>
    #include "my_mem.h"

/** cell_t struct for linked lists cells
 * @param prev pointer to previous cell in the list (NULL if no previous)
 * @param data pointer to data stored in this cell
 * @param next pointer to next cell in the list (NULL if no next)
 */
typedef struct cell_s {
    struct cell_s *prev;
    void *data;
    struct cell_s *next;
} cell_t;

/** linked_list_t struct for linked lists
 * @param head pointer to first cell in the list
 * @param tail pointer to last cell in the list
 * @note if both are NULL then list is empty
 */
typedef struct linked_list_s {
    cell_t *head;
    cell_t *tail;
} linked_list_t;


//------------------------- initializations -------------------------//

/** initialize an empty linked list
 * @return linked list
 * OR NULL on error
 */
linked_list_t *init_linked_list(void);

/** create a new cell at the beginning of the list to store data
 * @param list linked list to extend
 * @param data pointer to data you wish to store
 * @return list
 * OR NULL on error
 * @note can be used for creation of the first cell in the list
 */
linked_list_t *add_as_head(linked_list_t *list, void *data);

/** create a new cell at the end of the list to store data
 * @param list linked list to extend
 * @param data pointer to data you wish to store
 * @return list
 * OR NULL on error
 * @note can be used for creation of the first cell in the list
 */
linked_list_t *add_as_tail(linked_list_t *list, void *data);


//------------------------- frees -----------------------------------//

/** delete a cell from a list
 * @param list list to delete from
 * @param cell cell to free
 * @note freeing a cell will NOT free the data it holds
 */
void free_cell(linked_list_t *list, cell_t *cell);

/** free a list and it's cells
 * @param list list to delete
 * @note all cells will be destroyed but their data will NOT be destroyed
 */
void free_linked_list(linked_list_t *list);


//------------------------- interactions ----------------------------//

/** exchange the data of 2 cells
 * @param c1 1st cell to swap
 * @param c2 2nd cell to swap
 * @note works with any cells even from different linked lists
 */
void swap_cells(cell_t *c1, cell_t *c2);

/** get the number of cells in a list
 * @param list list to get size of
 * @return number of cells in list
 */
int get_linked_list_size(linked_list_t *list);

#endif /* MY_LINKED_LIST_H */
