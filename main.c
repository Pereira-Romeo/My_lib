/*
** EPITECH PROJECT, 2024
** main
** File description:
** testing the library
*/

#include "my.h"
#include <math.h>
#include <stdio.h>

int main(void)
{
    char *str = "hello why not, i am dying.\nwaaaaaaaaaahhhhhh\n";
    char *separator = " \n\t";
    int str_index = 0;
    int c_index = 0;
    int found = 0;

    found = one_c_is_in(separator, str + 20, &str_index, &c_index);
    printf("%s%c%s%.0d\n", (found) ? "found '" : "found nothing",
    (found) ? separator[c_index] : '.',
    (found) ? "' at: " : "",
    (found) ? str_index : 0);
    found = one_c_is_in(separator, str + my_strlen(str), &str_index, &c_index);
    printf("%s%c%s%.0d\n", (found) ? "found '" : "found nothing",
    (found) ? separator[c_index] : '.',
    (found) ? "' at: " : "",
    (found) ? str_index : 0);
    return 0;
}
