/*
** EPITECH PROJECT, 2024
** my_count_number.c
** File description:
** 3 funcs to count the digits of numbers
*/

int my_intlen(int nb)
{
    int dig = 0;

    if (nb <= 0) {
        dig++;
        nb *= -1;
    }
    while (nb > 0) {
        dig++;
        nb /= 10;
    }
    return dig;
}

int my_lgilen(long int nb)
{
    int dig = 0;

    if (nb <= 0) {
        dig++;
        nb *= -1;
    }
    while (nb > 0) {
        dig++;
        nb /= 10;
    }
    return dig;
}

int my_llilen(long long int nb)
{
    int dig = 0;

    if (nb <= 0) {
        dig++;
        nb *= -1;
    }
    while (nb > 0) {
        dig++;
        nb /= 10;
    }
    return dig;
}
