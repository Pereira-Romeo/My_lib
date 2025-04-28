/*
** EPITECH PROJECT, 2025
** my_lib_off
** File description:
** my_perror_tests
*/

#include "my.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>

/*
int write_all_errors_in_test_files(void)
{
    int my_perror_fd = create_file("./test/my_perror.out", 00762);
    int perror_fd = create_file("./test/perror.out", 00762);

    if (dup2(my_perror_fd, STDERR_FILENO) == -1)
        return 84;
    close_file(my_perror_fd);
    for (int i = 1; i <= NB_ERR_MESS; i++) {
        my_perror(NULL, i, 0);
    }
    if (dup2(perror_fd, STDERR_FILENO) == -1)
        return 84;
    close_file(perror_fd);
    for (int i = 1; i <= NB_ERR_MESS; i++) {
        write(STDERR_FILENO, strerror(i), my_strlen(strerror(i)));
        write(STDERR_FILENO, ".\n", 2);
    }
    return 0;
}
---------------THIS FUNC BREAKS THE CODING STYLE CHECKER----------------
//shows i + 1 because we did not write errno 0 in the error output
int compare_outputs(char **my_perror_list, char **perror_list)
{
    for (int i = 0; i < NB_ERR_MESS; i++) {
        if (my_strcmp(my_perror_list[i],  perror_list[i]) == 0) {
            printf("%-51s\t%-51s\t\e[0;34;merrno i: %3d "
            "\e[1;32mcorrespond\e[0m\n",
            my_perror_list[i],  perror_list[i], i + 1);
        } else {
            printf("%-51s\t%-51s\t\e[0;34;merrno i: %3d "
            "\e[1;31mdon't correspond\e[0m\n",
            my_perror_list[i],  perror_list[i], i + 1);
        }
    }
    free_strtab(my_perror_list);
    free_strtab(perror_list);
    return 0;
}


int compare_outputs_handler(void)
{
    char *my_perror_out = read_file("./test/my_perror.out");
    char *perror_out = read_file("./test/perror.out");
    char **my_perror_list = NULL;
    char **perror_list = NULL;

    if (!my_perror_out || !perror_out) {
        if (my_perror_out)
            free(my_perror_out);
        if (perror_out)
            free(perror_out);
        return 84;
    }
    my_perror_list = str_to_warr(my_perror_out, "\n");
    perror_list = str_to_warr(perror_out, "\n");
    if (!my_perror_list || !perror_list) {
        if (my_perror_list)
            free_strtab(my_perror_list);
        if (perror_list)
            free_strtab(perror_list);
        return 84;
    }
    return compare_outputs(my_perror_list, perror_list);
}

int main(void)
{
    if (write_all_errors_in_test_files() == 0)
        return compare_outputs_handler();
    return 84;
}*/
