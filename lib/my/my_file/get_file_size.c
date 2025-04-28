/*
** EPITECH PROJECT, 2025
** my_radar_v0.1
** File description:
** get_file_size
*/

#include "../headers/my_file.h"
#include <sys/stat.h>

int get_file_size(char *filepath)
{
    struct stat info;

    if (stat(filepath, &info) == -1)
        return my_lperror("get_file_size", -1);
    return info.st_size;
}
