/*
** EPITECH PROJECT, 2024
** my_math.h
** File description:
** my math header
*/

#ifndef MY_MATH_H
    #define MY_MATH_H
//transform decimal int nb into the desired base (with lowercase letters)
int base_switcher(int nb, int base);
//transform decimal int nb into the desired base (with uppercase letters)
int base_switcher_maj(int nb, int base);
//return the length of the transformed number
int base_switcher_size(int nb, int base);
//find the closest superior prime number
int my_find_prime_sup(int nb);
//return 1 if number is negative, 0 if positive
int my_isneg(int n);
//return 1 if number is prime, 0 if not
int my_isprime(int nb);
//retrieves the first int in str
int my_getnbr(char *str);
//retrives the first int in str starting at i
int my_getnbr_from(const char *str, int i);
//return nb to the power of p
int my_power(int nb, int p);
//return the swaure root of nb if its square root is a whole number
int my_square_root(int nb);
//Get the square root of a number
//@param nb a number
//@returns the square root of nb
//@note this function has a max precision of e-15 (15 digits after the unit)
double my_sqrt(double nb);
#endif /* MY_MATH_H */
