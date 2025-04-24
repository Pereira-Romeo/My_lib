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
    char *str = "hello why not, i am dying, wtf is going on i can't use any of those letters aaaaaaaaaaaaaaaaah\n";
    int index = 0;
    int found = 0;

    found = my_char_is_in('h', str, &index);
    printf("%s 'p' in str, index: %d and len: %d\n",
    (found) ? "found" : "didn't find", index, my_strlen(str));
    return 0;
}
