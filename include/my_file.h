/*
** EPITECH PROJECT, 2025
** my_radar_v0.1
** File description:
** my_files
*/

#ifndef MY_FILES_H
    #define MY_FILES_H
    #include <unistd.h>
    #include "my_errno.h"

//Create a file with given rights
//@param filepath file to create
//@param mode rights to give to the file
//@returns file descriptor
//OR -1 on failure/error
//@note if the file already exists, will empty it and open it
int create_file(char *filepath, int mode);
//open a file with read access
//@param filepath file to open
//@returns file descriptor
//OR -1 on failure
int open_file(char const *filepath);
//Close a file descriptor
//@param fd file descriptor to close
//@returns 0
//OR -1 on error
int close_file(int fd);

//Read a file and return it's content in a malloc'd string
//@param filepath file to read
//@returns malloc'd string
//OR NULL on failure/error
char *read_file(char *filepath);

//get the size of a file
//@param filepath file to get the size of
//@returns size of file
//OR -1 on failure
int get_file_size(char *filepath);

#endif /* MY_FILE_H */
