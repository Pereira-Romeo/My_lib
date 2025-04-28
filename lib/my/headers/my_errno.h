/*
** EPITECH PROJECT, 2025
** my_lib_off
** File description:
** my_perror
*/

#ifndef MY_PERROR_H
    #define MY_PERROR_H
    #include <unistd.h>
    #include <errno.h>
    #include "my_bool.h"
    //set at TRUE to let library print error messages, set at FALSE to prevent
    #define LIB_PRINT_ERROR TRUE
    #define NB_ERR_MESS 133 //number of error messages available
    #define ESUC 0 //Success.

/** struct to carry message and it's size
 * @param e_mess string of the error message
 * @param mess_size the size of the string
 */
typedef struct err_val_s {
    char *e_mess;
    int mess_size;
} errs_t;

/** Write error message corresponding to err
 * @param str if not NULL, adds [str: ] before the error message
 * @param err value of the error, use defines from errno.h or my_errno.h
 * or the global variable errno
 * @param val value to return
 * @returns val
 */
int my_puterr(char *str, int err, int val);

/** Write error message corresponding to errno
 * @param str if not NULL, adds [str: ] before the error message
 * @param val value to return
 * @returns val
 */
int my_perror(char *str, int val);

/** Write error message corresponding to err
 * @param str if not NULL, adds [str: ] before the error message
 * @param err value of the error, use defines from errno.h or my_errno.h
 * or the global variable errno
 * @param val value to return
 * @returns val
 * @note If LIB_PRINT_ERROR is FALSE, this function will not print anything.
 * If LIB_PRINT_ERROR is TRUE, it will print the error
 */
int my_lputerr(char *str, int err, int val);

/** Write error message corresponding to errno
 * @param str if not NULL, adds [str: ] before the error message
 * @param val value to return
 * @returns val
 * @note If LIB_PRINT_ERROR is FALSE, this function will not print anything.
 * If LIB_PRINT_ERROR is TRUE, it will print the error
 */
int my_lperror(char *str, int val);

#endif /* MY_PERROR_H */
