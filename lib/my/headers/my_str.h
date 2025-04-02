/*
** EPITECH PROJECT, 2024
** my_str.h
** File description:
** my str lib
*/

#ifndef MY_STR_H
    #define MY_STR_H
    #include <stddef.h>
    #include "my_bool.h"

//my_*len.c

//Finds the length of str
//@param str string
//@return length of str
int my_strlen(char *str);
//Finds the length from index n to the
//next occurrence of atleast one character inside c
//@param str string
//@param n index to start at
//@param c list of characters to stop at
//@return length beteween n and first occurence of a char of c
int mstrn_to_clen(char *str, int n, char *c);
//Finds the number of digits in nb
//@param nb int
//@return length of nb
int my_intlen(int nb);
//Finds the number of digits in nb
//@param nb long long int
//@return length of nb
int my_llilen(long long int nb);

//Set any character to 0 between n and the first occurence of c
//@param src string to modify
//@param n index to start at
//@param c char to stop at
//@param backwards set at 1 to go from n to beginning, 0 for n to end
//@returns on success 0 || on error: 1 (backwards had invalid value)
int nullify_from_till(char *src, int n, char c, int backward);

//my_findstr.c

//Looks for to_find in str
//@param str string
//@param to_find string to find in str
//@return pointer to str starting at the beginning of to_find
//or str if to_find wasn't found
char *my_strstr(char *str, char *to_find);


//my_is*.c

//Looks for c in str and store it's index if found
//@param c character to find
//@param str string to search in
//@param index address of int to store the index in
//@returns TRUE (1)
//OR FALSE (0)
//@note index can be NULL if you don't need it
int my_char_is_in(char c, char *str, int *index);
//Verify c is alphanumeric
//@param c character to check
//@returns TRUE (1)
//OR FALSE (0)
int my_char_isalnum(char const c);
//Verify c is alphabetical
//@param c character to check
//@returns TRUE (1)
//OR FALSE (0)
int my_char_isalpha(char const c);
//Verify c is anything but alphanumeric
//@param c character to check
//@returns TRUE (1)
//OR FALSE (0)
int my_char_isfence(char const c);
//Verify c is lowercase
//@param c character to check
//@returns TRUE (1)
//OR FALSE (0)
int my_char_islower(char const c);
//Verify c is numbers only (doesn't include '-')
//@param c character to check
//@returns TRUE (1)
//OR FALSE (0)
int my_char_isnumer(char const c);
//Verify c is printable (means you can see it)
//@param c character to check
//@returns TRUE (1)
//OR FALSE (0)
int my_char_isprint(char const c);
//Verify c is uppercase
//@param c character to check
//@returns TRUE (1)
//OR FALSE (0)
int my_char_isupper(char const c);
//Verify str is alphanumeric only
//@param c character to check
//@returns TRUE (1)
//OR FALSE (0)
int my_str_isalnum(char const *str);
//Verify str only contains alphanumeric or given special characters
//@param str string to verify
//@param specials list of allowed characters
//@returns TRUE (1)
//OR FALSE (0)
//@note Specials can be NULL but in that case, just use my_str_isalnum
int my_str_isalnum_and(char *str, char *specials);
//Verify str only contains letters (uppercase or lower case)
//@param str string to verify
//@returns TRUE (1)
//OR FALSE (0)
int my_str_isalpha(char const *str);
//Verify str only contains lowercase letters
//@param str string to verify
//@returns TRUE (1)
//OR FALSE (0)
int my_str_islower(char const *str);
//Verify str only contains numbers (doesn't include '-')
//@param str string to verify
//@returns TRUE (1)
//OR FALSE (0)
int my_str_isnumer(char const *str);
//Verify str only contains printable characters (means you can see it)
//@param str string to verify
//@returns TRUE (1)
//OR FALSE (0)
int my_str_isprint(char const *str);
//Verify str only contains uppercase letters
//@param str string to verify
//@returns TRUE (1)
//OR FALSE (0)
int my_str_isupper(char const *str);

//my_put*.c

//Write str in the standard error output
//@param str string to write
//@returns number of characters written
//OR -1 on error
int my_write_err(char *str);
//Write [name: err\n] in the standard error output
//@param name should be the name of program or func
//@param err the error that happened
//@returns number of characters written
//OR -1 on error
int my_puterr(char *name, char *err);
//Write c to the standard output
//@param c character to write
//@returns 1
int my_putchar(char const c);
//Write an int to the standard output
//@param nb number to write
//@returns number characters written
int my_putint(int nb);
//Write a long long int to the standard output
//@param nb number to write
//@returns number characters written
int my_putlli(long long int nb);
//Write a string to the standard output
//@param str string to write
//@returns number characters written
int my_putstr(char *str);
//Write a string to the standard output
//starting at i up to end
//@param str string to write
//@param i index to start at
//@param end index to stop at
//@returns number characters written
int my_putstr_i_end(char *str, int i, int end);

//malloc a new string and write nb in it
//@param nb number to write
//@returns malloc'd string
//OR NULL on error
char *int_to_str(int nb);

//my_revstr.c

//modify str to write it in reverse
//@param str string to reverse
//@returns pointer to str
char *my_revstr(char *str);


//my_str| capitalize | upcase | lowcase |.c

//Change first letter of every word to uppercase
//@param str string to modify
//@returns pointer to str
char *my_strcapitalize(char *str);
//all letters become lowercase
//Change all letters to lowercase
//@param str string to modify
//@returns pointer to str
char *my_strlowcase(char *str);
//Change all letters to uppercase
//@param str string to modify
//@returns pointer to str
char *my_strupcase(char *str);


//my_str_to_warr.c

//malloc a new list of strings and write every words in it
//@param str string to make list of word from
//@param separator separators that should seperate every word
//@returns pointer to malloc list of string
//OR NULL on error
//@note separator can be NULL to use default separators wich are
//"[space]\\n\\0"
char **str_to_warr(char *str, char *separator);
//malloc a new list of strings and write every words in it
//@param str string to make list of word from
//@param separator separators that should seperate every word
//@returns pointer to malloc list of string
//OR NULL on error
//@note separator can be NULL to use default separators wich are
//"[space]\\n\\0"
char **str_to_warr_from(char *str, char *separator, int n);
//free a word array
//Deprecated do not use
void free_warr(char **warr);

//my_nb_words.c

//counts the number of words in str
//@param str string to count the words in
//@param separator list of characters used to seperate words
//@returns number of words in str
//@note separator can be NULL to use default separators wich are
//"[space]\\n\\0"
int my_nb_words(char *str, char *separator);



//my_strcat.c

//concatenate src at the end of dest
//@param dest destination of the cat
//@param src src of the cat
//@returns pointer to dest
//@note dest needs to be big enough as my_strcat does not realloc nor alloc
char *my_strcat(char *dest, char *src);
//concatenate src up to n at the end of dest
//@param dest destination of the cat
//@param src src of the cat
//@param n length of src to cat
//@returns pointer to dest
//@note dest needs to be big enough as my_strcat does not realloc nor alloc
char *my_strncat(char *dest, char *src, int n);
//concatenate src from n up to m at the end of dest
//@param dest destination of the cat
//@param src src of the cat
//@param n index of src to start cat
//@param m length of src to cat
//@returns pointer to dest
//@note dest needs to be big enough as my_strcat does not realloc nor alloc
char *mstrn_to_mcat(char *dest, char *src, int n, int m);


//my_strcmp.c

//compare s1 and s2
//@param s1 string
//@param s2 string
//@returns 0 if s1 and s2 are the same
//OR the difference between the first character that is different
int my_strcmp(char const *s1, char const *s2);
//compare s1 and s2 up to n
//@param s1 string
//@param s2 string
//@param n length to compare
//@returns 0 if s1 and s2 are the same
//OR the difference between the first character that is different
int my_strncmp(char const *s1, char const *s2, int n);


//my_strcpy.c

//copy src into dest
//@param dest destination of the copy
//@param src source to copy
//@returns pointer to dest
//@note dest needs to be big enough as my_strcpy does not realloc nor alloc
char *my_strcpy(char *dest, char *src);
//copy src up to n into dest
//@param dest destination of the copy
//@param src source to copy
//@param n length of src to copy
//@returns pointer to dest
//@note dest needs to be big enough as my_strcpy does not realloc nor alloc
char *my_strncpy(char *dest, char *src, int n);
//copy src from n up to c into dest
//@param dest destination of the copy
//@param src source to copy
//@param n length of src to copy
//@returns pointer to dest
//@note dest needs to be big enough as my_strcpy does not realloc nor alloc
char *mstrn_to_ccpy(char *dest, char *src, int n, char c);
//copy src from n up to m into dest
//@param dest destination of the copy
//@param src soucre to copy
//@param n index to start copy
//@param m index to stop copy
//@returns pointer to dest
//@note dest needs to be big enough as my_strcpy does not realloc nor alloc
//@note also, if m is greater than the last index of src, it copies up to the end
char *mstrn_to_mcpy(char *dest, char *src, int n, int m);
//cpy src starting at n into dest
//@param dest destination of the copy
//@param src source to copy
//@param n index to start copying from
//@returns pointer to dest
//@note dest needs to be big enough as my_strcpy does not realloc nor alloc
char *my_strcpy_from(char *dest, char *src, int n);

//my_strdup.c

//duplicate a string
//@param src string to duplicate
//@returns malloc'd string
//OR NULL on error
char *my_strdup(char *src);
//duplicate a string starting at n
//@param src string to duplicate
//@param n index to start duplicating at
//@returns malloc'd string
//OR NULL on error
char *my_strdup_from(char *src, int n);
//duplicate src until c is met
//@param src string to duplicate
//@param c character to stop at
//@returns malloc'd string
//OR NULL on error
char *strdup_till(char *src, char c);

//my_strdupcat.c

//duplicate s1 and cat s2 to s1
//@param s1 string to duplicate
//@param s2 string to cat to s1
//@returns malloc'd string
//OR NULL on error
//@note if s1 is NULL but not s2, is equivalent to my_strdup(s2)
//@note if s2 is NULL but not s1, is equivalent to my_strdup(s1)
char *strdupcat(char *s1, char *s2);
//duplicate s1 and cat s2 and s3 to s1
//@param s1 string to duplicate
//@param s2 string to cat to s1 first
//@param s3 string to cat to s1 in 2nd
//@returns malloc'd string
char *strdup2cat(char *s1, char *s2, char *s3);
//duplicate s1 up to n and cat s2 to s1
//@param s1 string to duplicate
//@param s2 string to cat to s1
//@param n length of s1 to duplicate
char *strdupncat(char *s1, char *s2, int n);
#endif /* MY_STR_H */
