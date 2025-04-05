/*
** EPITECH PROJECT, 2024
** main
** File description:
** testing the library
*/

#include "my.h"

int main(void)
{
    char *str = "Here we are. Testing a new str to word array yet again."
    "#this part here simulates a comment in a asm file of python file"
    "and this str to word array should ignore everything behind #";
    char **warr = str_to_warr_until(str, NULL, '#');

    str_puttab(warr, "\n");
    my_putchar('\n');
    free_strtab(warr);
    return 0;
}
