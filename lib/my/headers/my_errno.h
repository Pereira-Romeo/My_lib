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
    #define LIB_PRINT_ERROR 1
    #define NB_ERR_MESS 133
    #define ESUC 0 //Success.

//struct to carry message and it's size
typedef struct err_val_s {
    char *e_mess;
    int mess_size;
} errs_t;

//Write message corresponding to err
//@param str if not NULL, adds [str: ] before the error message
//@param err value of the error, use defines from errno.h
//or special defines from my_errno.h
//@param val value to return
//@returns val
int my_perror(char *str, int err, int val);

//Same as my_perror but won't print if LIB_MY_PRINT is set to 0
//Used in the library.
//@param str if not NULL, adds [str: ] before the error message
//@param err value of the error
//@param val value to return
//@returns val
int my_lperror(char *str, int err, int val);

#endif /* MY_PERROR_H */
