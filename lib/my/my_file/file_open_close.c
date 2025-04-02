/*
** EPITECH PROJECT, 2024
** file open close
** File description:
** funcs to open and close files
*/

#include "../headers/my_file.h"
#include <fcntl.h>


int create_file(char *filepath, int mode)
{
    int fd = open(filepath, O_CREAT | O_WRONLY | O_TRUNC, mode);

    if (fd == -1)
        write(STDERR_FILENO, "create_file: cannot create\n", 27);
    return fd;
}

int open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        write(STDERR_FILENO, "open_file: cannot open\n", 23);
    return fd;
}

int close_file(int fd)
{
    if (close(fd) == -1) {
        write(STDERR_FILENO, "close_file: cannot close\n", 25);
        return -1;
    }
    return 0;
}
