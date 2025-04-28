/*
** EPITECH PROJECT, 2024
** my lib
** File description:
** header of my_str sub-library
*/

#ifndef MY_STR_H
    #define MY_STR_H
    #include <stddef.h>
    #include "my_bool.h"

//my_*len.c

/** Finds the length of str
 * @param str string
 * @return length of str
 */
int my_strlen(char *str);

/** Finds the length from index n to the
 * next occurrence of atleast one character inside c
 * @param str string
 * @param n index to start at
 * @param c list of characters to stop at
 * @return length beteween n and first occurence of a char of c
 */
int mstrn_to_clen(char *str, int n, char *c);

/** Finds the number of digits in nb
 * @param nb int
 * @return length of nb
 */
int my_intlen(int nb);

/** Finds the number of digits in nb
 * @param nb long long int
 * @return length of nb
 */
int my_llilen(long long int nb);

/** Set any character to 0 between n and the first occurence of c
 * @param src string to modify
 * @param n index to start at
 * @param c char to stop at
 * @param backwards set at 1 to go from n to beginning, 0 for n to end
 * @returns 0
 * OR 1 (only fails if backward had invalid value)
 */
int nullify_from_till(char *src, int n, char c, int backward);


/** Looks for to_find in str
 * @param str string
 * @param to_find string to find in str
 * @return pointer to str starting at the beginning of to_find
 * OR str if to_find wasn't found
 */
char *my_strstr(char *str, char *to_find);


//my_is*.c

/** Looks for c in str and store it's index
 * @param c character to find
 * @param str string to search in
 * @param index address of int to store the index in
 * @returns TRUE (1)
 * OR FALSE (0)
 * @note index can be NULL if you don't need it. Also if c wasn't found
 * index will be equal to the length of str
 */
int my_char_is_in(char c, char *str, int *index);

/** Verify c is alphanumeric
 * @param c character to check
 * @returns TRUE (1)
 * OR FALSE (0)
 */
int my_char_isalnum(char const c);

/** Verify c is alphabetical
 * @param c character to check
 * @returns TRUE (1)
 * OR FALSE (0)
 */
int my_char_isalpha(char const c);

/** Verify c is anything but alphanumeric
 * @param c character to check
 * @returns TRUE (1)
 * OR FALSE (0)
 */
int my_char_isfence(char const c);
/** Verify c is lowercase
 * @param c character to check
 * @returns TRUE (1)
 * OR FALSE (0)
 */
int my_char_islower(char const c);

/** Verify c is numbers only (doesn't include '-')
 * @param c character to check
 * @returns TRUE (1)
 * OR FALSE (0)
 */
int my_char_isnumer(char const c);

/** Verify c is printable (means you can see it)
 * @param c character to check
 * @returns TRUE (1)
 * OR FALSE (0)
 */
int my_char_isprint(char const c);

/** Verify c is uppercase
 * @param c character to check
 * @returns TRUE (1)
 * OR FALSE (0)
 */
int my_char_isupper(char const c);

/** Looks in str, for one of the char contained in c, store the index
 * of wich char in c was encountered and the index of where it was found
 * @param c list of characters to find
 * @param str string in wich to look for one of the characters
 * @param str_index if not NULL, store the index of the char inside of str
 * @param c_index if not NULL, store the index the of char inside of c
 * @returns TRUE (1)
 * OR FALSE (0)
 */
int one_c_is_in(char *c, char *str, int *str_index, int *c_index);

/** Verify str is alphanumeric only
 * @param c character to check
 * @returns TRUE (1)
 * OR FALSE (0)
 */
int my_str_isalnum(char const *str);

/** Verify str only contains alphanmeric or given special characters
 * @param str string to verifys
 * @param specials list of allowed characters
 * @returns TRUE (1)
 * OR FALSE (0)
 * @note Specials can be NULL but in that case, just use my_str_isalnum
 * int my_str_isalnum_and(char *str, char *specials);
 * Verify str only contains letters (uppercase or lower case)
 * @param str string to verify
 * @returns TRUE (1)
 * OR FALSE (0)
 */
int my_str_isalpha(char const *str);

/** Verify str only contains lowercase letters
 * @param str string to verify
 * @returns TRUE (1)
 * OR FALSE (0)
 */
int my_str_islower(char const *str);

/** Verify str it a number
 * @param str string to verify
 * @param include_negatives set at True to include '-' as a number
 * @returns TRUE (1)
 * OR FALSE (0)
 */
int my_str_isnumer(char const *str, int include_negatives);

/** Verify str only contains printable characters (means you can see it)
 * @param str string to verify
 * @returns TRUE (1)
 * OR FALSE (0)
 */
int my_str_isprint(char const *str);

/** Verify str only contains uppercase letters
 * @param str string to verify
 * @returns TRUE (1)
 * OR FALSE (0)
 */
int my_str_isupper(char const *str);

//my_put*.c

/** Write c to the standard output
 * @param c character to write
 * @returns 1
 */
int my_putchar(char const c);

/** Write an int to the standard output
 * @param nb number to write
 * @returns number characters written
 */
int my_putint(int nb);

/** Write a long long int to the standard output
 * @param nb number to write
 * @returns number characters written
 */
int my_putlli(long long int nb);

/** Write a string to the standard output
 * @param str string to write
 * @returns number characters written
 */
int my_putstr(char *str);

/** Write a string to the standard output
 * starting at i up to end
 * @param str string to write
 * @param i index to start at
 * @param end index to stop at
 * @returns number characters written
 */
int my_putstr_i_end(char *str, int i, int end);

/** Malloc a new string and write nb in it
 * @param nb number to write
 * @returns malloc'd string
 * OR NULL on error
 */
char *int_to_str(int nb);

//my_revstr.c

/** Modify str to write it in reverse
 * @param str string to reverse
 * @returns pointer to str
 */
char *my_revstr(char *str);


//my_str| capitalize | upcase | lowcase |.c

/** Change first letter of every word to uppercase
 * @param str string to modify
 * @returns pointer to str
 */
char *my_strcapitalize(char *str);

/** Change all letters to lowercase
 * @param str string to modify
 * @returns pointer to str
 */
char *my_strlowcase(char *str);

/** Change all letters to uppercase
 * @param str string to modify
 * @returns pointer to str
 */
char *my_strupcase(char *str);


//string to word array:

/** Malloc a new list of strings and write every words in it
 * @param str string to make list of word from
 * @param separator separators that should seperate every word
 * @returns pointer to malloc list of string
 * OR NULL on error
 * @note separator can be NULL to use default separators wich are
 * "[space]\\n\\0"
 */
char **str_to_warr(char *str, char *separator);

/** Malloc a new list of strings and write every words in it,
 * starting at index n
 * @param str string to make list of word from
 * @param separator separators that should seperate every word
 * @param n index to start at
 * @returns pointer to malloc list of string
 * OR NULL on error
 * @note separator can be NULL to use default separators wich are
 * "[space]\\n\\0"
 */
char **str_to_warr_from(char *str, char *separator, int n);

/** Malloc a new list of strings and write every words in it,
 * stopping ar the first occurrence of c.
 * If c isn't met, behaves like simple str_to_warr call.
 * @param str string to make list of word from
 * @param separator separators that should seperate every word
 * @param c character to stop at
 * @returns pointer to malloc list of string
 * OR NULL on error
 * @note separator can be NULL to use default separators wich are
 * "[space]\\n\\0"
 */
char **str_to_warr_until(char *str, char *separator, char c);

//my_nb_words.c

/** Counts the number of words in str
 * @param str string to count the words in
 * @param separator list of characters used to seperate words
 * @returns number of words in str
 * @note separator can be NULL to use default separators wich are
 * "[space]\\n\\0"
 */
int my_nb_words(char *str, char *separator);



//my_strcat.c

/** Concatenate src at the end of dest
 * @param dest destination of the cat
 * @param src src of the cat
 * @returns pointer to dest
 * @note dest needs to be big enough as my_strcat does not realloc nor alloc
 */
char *my_strcat(char *dest, char *src);

/** Concatenate src up to n at the end of dest
 * @param dest destination of the cat
 * @param src src of the cat
 * @param n length of src to cat
 * @returns pointer to dest
 * @note dest needs to be big enough as my_strcat does not realloc nor alloc
 */
char *my_strncat(char *dest, char *src, int n);

/** Concatenate src from n up to m at the end of dest
 * @param dest destination of the cat
 * @param src src of the cat
 * @param n index of src to start cat
 * @param m length of src to cat
 * @returns pointer to dest
 * @note dest needs to be big enough as my_strcat does not realloc nor alloc
 */
char *mstrn_to_mcat(char *dest, char *src, int n, int m);


//my_strcmp.c

/** Compare s1 and s2
 * @param s1 string
 * @param s2 string
 * @returns 0 if s1 and s2 are the same
 * OR the difference between the first character that is different
 */
int my_strcmp(char const *s1, char const *s2);

/** Compare s1 and s2 up to n
 * @param s1 string
 * @param s2 string
 * @param n length to compare
 * @returns 0 if s1 and s2 are the same
 * OR the difference between the first character that is different
 */
int my_strncmp(char const *s1, char const *s2, int n);


//my_strcpy.c

/** Copy src into dest
 * @param dest destination of the copy
 * @param src source to copy
 * @returns pointer to dest
 * @note dest needs to be big enough as my_strcpy does not realloc nor alloc
 */
char *my_strcpy(char *dest, char *src);

/** Copy src up to n into dest
 * @param dest destination of the copy
 * @param src source to copy
 * @param n length of src to copy
 * @returns pointer to dest
 * @note dest needs to be big enough as my_strcpy does not realloc nor alloc
 */
char *my_strncpy(char *dest, char *src, int n);

/** Copy src from n up to c into dest
 * @param dest destination of the copy
 * @param src source to copy
 * @param n length of src to copy
 * @returns pointer to dest
 * @note dest needs to be big enough as my_strcpy does not realloc nor alloc
 */
char *mstrn_to_ccpy(char *dest, char *src, int n, char c);

/** Copy src from n up to m into dest
 * @param dest destination of the copy
 * @param src soucre to copy
 * @param n index to start copy
 * @param m index to stop copy
 * @returns pointer to dest
 * @note dest needs to be big enough as my_strcpy does not realloc nor alloc
 * @note also, if m is greater than the last index of src,
 * it copies up to the end
 */
char *mstrn_to_mcpy(char *dest, char *src, int n, int m);

/** Copy src starting at n into dest
 * @param dest destination of the copy
 * @param src source to copy
 * @param n index to start copying from
 * @returns pointer to dest
 * @note dest needs to be big enough as my_strcpy does not realloc nor alloc
 */
char *my_strcpy_from(char *dest, char *src, int n);

//my_strdup.c

/** Duplicate a string
 * @param src string to duplicate
 * @returns malloc'd string
 * OR NULL on error
 */
char *my_strdup(char *src);

/** Duplicate a string starting at n
 * @param src string to duplicate
 * @param n index to start duplicating at
 * @returns malloc'd string
 * OR NULL on error
 */
char *my_strdup_from(char *src, int n);

/** Duplicate src until c is met
 * @param src string to duplicate
 * @param c character to stop at
 * @returns malloc'd string
 * OR NULL on error
 */
char *strdup_till(char *src, char c);

//my_strdupcat.c

/** Duplicate s1 and cat s2 to s1
 * @param s1 string to duplicate
 * @param s2 string to cat to s1
 * @returns malloc'd string
 * OR NULL on error
 * @note if s1 is NULL but not s2, is equivalent to my_strdup(s2)
 * @note if s2 is NULL but not s1, is equivalent to my_strdup(s1)
 */
char *strdupcat(char *s1, char *s2);

/** Duplicate s1 and cat s2 and s3 to s1
 * @param s1 string to duplicate
 * @param s2 string to cat to s1 first
 * @param s3 string to cat to s1 in 2nd
 * @returns malloc'd string
 */
char *strdup2cat(char *s1, char *s2, char *s3);

/** Duplicate s1 up to n and cat s2 to s1
 * @param s1 string to duplicate
 * @param s2 string to cat to s1
 * @param n length of s1 to duplicate
 */
char *strdupncat(char *s1, char *s2, int n);
#endif /* MY_STR_H */
