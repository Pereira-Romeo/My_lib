/*
** EPITECH PROJECT, 2024
** d05 - my_compute_square_root
** File description:
** return the root of nb if is a whole number
** if is not a whole nnumber, return the next whole number
** result will always be >= the real root
*/

#include "../headers/my_math.h"

static
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

int my_square_root(int nb)
{
    int i = 0;

    while (i * i != nb) {
        if (i * i >= nb)
            return i;
        i++;
    }
    return i;
}

static
double my_sqrt_basic_check(double nb, double max_precision, int val)
{
    if (nb == 0)
        return 0;
    if (nb == 1)
        return 1;
    if (nb == 2)
        return SQRT_2;
    if (nb >= MAX_SQRT_VALUE) {
        if (val)
            return my_lputerr("my_sqrt", EOVERFLOW, 0);
        else
            return 0;
    }
    if (max_precision >= 1) {
        if (val)
            return my_lputerr("my_sqrt", EOVERFLOW, 0);
        else
            return 0;
    }
    return -1;
}

double my_sqrt(double nb)
{
    double root = 0;
    double val = 0.1;
    double max_precision = MAX_SQRT_PRECISION * (my_llilen(nb) * 10);

    if (my_sqrt_basic_check(nb, max_precision, 1) != -1)
        return my_sqrt_basic_check(nb, max_precision, 0);
    root = my_square_root(nb);
    while (val > max_precision && root * root != nb) {
        if (root * root < nb) {
            root += val;
            val /= 10;
        }
        if (root * root <= nb)
            break;
        root -= val;
    }
    return root;
}
