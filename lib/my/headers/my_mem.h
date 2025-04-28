/*
** EPITECH PROJECT, 2025
** my_lib
** File description:
** header of my_mem sub-library
*/

#ifndef INCLUDED_MY_MEM_H
    #define INCLUDED_MY_MEM_H
    #include <unistd.h>
    #include <stdlib.h>
    #include "my_bool.h"
    #include "my_errno.h"

    #if __BYTE_ORDER == __LITTLE_ENDIAN
        #define MY_SWAP_ENDIAN TRUE
    #else
        #define MY_SWAP_ENDIAN FALSE
    #endif /* MY_SWAP_ENDIAN */

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
