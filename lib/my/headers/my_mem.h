/*
** EPITECH PROJECT, 2025
** My_lib
** File description:
** my_mem
*/

#ifndef INCLUDED_MY_MEM_H
    #define INCLUDED_MY_MEM_H
    #include <unistd.h>
    #include <stdlib.h>

/** allocate memory and initialize it to NULL
 * @param nmemb number of members
 * @param bytes size of each members in bytes
 * @returns pointer to allocated memory
 * OR NULL on error
 */
void *my_calloc(int nmemb, int bytes);

/** free a list of string
 * @param tab list to free
 * @returns NULL
 */
char **free_strtab(char **tab);

/** get the swapped the endians of an int
 * @param int int to swap endians of
 * @returns the swapped value
 */
int swap_int_endians(int value);

#endif
