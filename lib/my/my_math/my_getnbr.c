/*
** EPITECH PROJECT, 2024
** d04 - my_getnbr
** File description:
** returns the nb sent as a str
*/

int my_getnbr(const char *str)
{
    int nb = 0;
    int nbr_of_minus = 0;
    int i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            nbr_of_minus++;
        i = i + 1;
    }
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10;
        nb = nb + str[i] - 48;
        i = i + 1;
    }
    if (nbr_of_minus % 2 == 1)
        return nb * -1;
    return nb;
}

int my_getnbr_from(const char *str, int i)
{
    int nb = 0;
    int nbr_of_minus = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            nbr_of_minus++;
        i = i + 1;
    }
    while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10;
        nb = nb + str[i] - 48;
        i = i + 1;
    }
    if (nbr_of_minus % 2 == 1)
        return nb * -1;
    return nb;
}
