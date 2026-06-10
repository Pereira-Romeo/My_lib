/*
** EPITECH PROJECT, 2024
** main
** File description:
** testing the library
*/

#include "../include/my.h"
#include <uuid/uuid.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    uuid_t id = {0};
    char id_str[36] = {0};
    uuid_generate(id);
    uuid_unparse(id, id_str);
    my_printf("uuid: %s\n", id_str);

    char str[11] = "123456789\n";
    str[11] = 0;
    write(STDOUT_FILENO, str, sizeof(str));
    return 0;
}
