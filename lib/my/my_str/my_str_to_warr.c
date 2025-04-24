/*
** EPITECH PROJECT, 2025
** my_radarv0.2
** File description:
** my_str_to_word_array
*/

#include "../headers/my_str.h"
#include "../headers/my_mem.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

static
int nb_words_basic_check(char *str, char *separator)
{
    if (str == NULL)
        return 0;
    if (my_strlen(str) == 0)
        return 0;
    if (my_strlen(str) == 1) {
        if (my_char_is_in(str[0], separator, NULL))
            return 0;
        return 1;
    }
    return -1;
}

//if current char is separator and the one before wasn't: word++;
int my_nb_words(char *str, char *separator)
{
    char default_separator[3] = " \n\0";
    int words = 0;
    int i = 0;

    if (separator == NULL)
        separator = default_separator;
    if (nb_words_basic_check(str, separator) != -1)
        return nb_words_basic_check(str, separator);
    do {
        i++;
        if ((my_char_is_in(str[i], separator, NULL) || str[i] == '\0') &&
        !my_char_is_in(str[i - 1], separator, NULL) && str[i - 1] != '\0')
            words++;
    } while (str[i] != '\0');
    return words;
}

static
int add_word(char *word, char *str, int i, int Wlen)
{
    if (word == NULL)
        return 1;
    mstrn_to_mcpy(word, str, i - Wlen, i - 1);
    return 0;
}

static
int on_word(int *Wlen, char *str, int i, char *separator)
{
    char default_seperator[3] = " \n\0";

    if (separator == NULL)
        separator = default_seperator;
    if (!my_char_is_in(str[i], separator, NULL) && str[i] != '\0') {
        *Wlen += 1;
        return 1;
    }
    return 0;
}

static
int fill_warr(char **warr, char *str, int nb_words, char *separator)
{
    int tab_i = 0;
    int Wlen = 0;
    int error = 0;
    int i = -1;

    do {
        i++;
        if (on_word(&Wlen, str, i, separator))
            continue;
        if (Wlen != 0) {
            warr[tab_i] = my_calloc(Wlen + 1, sizeof(char));
            error = add_word(warr[tab_i], str, i, Wlen);
            Wlen = 0;
            tab_i++;
        }
        if (error)
            return 1;
    } while (tab_i < nb_words && str[i] != '\0');
    return 0;
}

char **str_to_warr(char *str, char *separator)
{
    int nb_words = my_nb_words(str, separator);
    char **warr = NULL;
    int error = 0;

    if (nb_words == 0)
        return NULL;
    warr = my_calloc(nb_words + 1, sizeof(char *));
    if (warr == NULL)
        return NULL;
    error = fill_warr(warr, str, nb_words, separator);
    if (error)
        return free_strtab(warr);
    return warr;
}

char **str_to_warr_from(char *str, char *separator, int n)
{
    char *tmp = my_strdup_from(str, n);
    char **warr = NULL;

    if (tmp == NULL)
        return NULL;
    warr = str_to_warr(tmp, separator);
    free(tmp);
    return warr;
}

char **str_to_warr_until(char *str, char *separator, char c)
{
    int index = 0;
    char *cpy = my_strdup(str);
    char **warr = NULL;

    if (!cpy)
        return NULL;
    if (my_char_is_in(c, str, &index))
        cpy[index] = '\0';
    warr = str_to_warr(cpy, separator);
    free(cpy);
    return warr;
}
