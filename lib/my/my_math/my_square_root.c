/*
** EPITECH PROJECT, 2024
** d05 - my_compute_square_root
** File description:
** return the root of nb if is a whole number
** if is not a whole nnumber, return the next whole number
** result will always be >= the real root
*/

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
double my_sqrt_basic_check(double nb)
{
    if (nb == 0)
        return 0;
    if (nb == 1)
        return 1;
    if (nb == 2)
        return 1.41421356237309504880;
    return -1;
}

double my_sqrt(double nb)
{
    double root = 0;
    double val = 0.1;

    if (my_sqrt_basic_check(nb) != -1)
        return my_sqrt_basic_check(nb);
    root = my_square_root(nb);
    while (val > 1.0e-15 && root * root != nb) {
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
