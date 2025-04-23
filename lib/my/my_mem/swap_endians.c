/*
** EPITECH PROJECT, 2025
** my_lib_off
** File description:
** swap_endians
*/

#include "../headers/my_mem.h"

//fetch byte1 and move it by 3 byte to left
//fetch byte2 and move it by 1 byte to left
//fetch byte3 and move it by 1 byte to right
//fetch byte4 and move it by 3 byte to right
//re-unite them with OR
int swap_int_endians(int value)
{
    int byte_1 = (value & 0x000000FF) << 24;
    int byte_2 = (value & 0x0000FF00) << 8;
    int byte_3 = (value & 0x00FF0000) >> 8;
    int byte_4 = (value & 0xFF000000) >> 24;

    return (byte_1 | byte_2 | byte_3 | byte_4);
}
