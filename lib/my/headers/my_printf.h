/*
** EPITECH PROJECT, 2025
** my_lib_off
** File description:
** my_printf
** excluding my_printf and my_dprintf, any functions in this header file
** should remain unused as they are subject to change and only intended
** to be used by my_printf and my_dprintf
*/

#ifndef MA_PRINTF_H
    #define MA_PRINTF_H
    #include <stddef.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include "my_errno.h"
    #include "my_bool.h"
    #include "my_str.h"
    #include "my_math.h"
    #define NB_SPE 20 //number of specifiers
    //characters to handle up to base 16 in lowercase
    #define BASE_CHARS "0123456789abcdef"
    //characters to handle up to base 16 in uppercase
    #define M_BASE_CHARS "0123456789ABCDEF"
    //base 16; hexa
    #define X_BASE 16
    //nb bits in int
    #define BITS_INT sizeof(int) * 8

/** write format to the standard output
 * @param format string containing the format
 * @param ... arguments corresponding to the formats
 * @returns number of characters written to the output
 * OR -1 on error
*/
int my_printf(char *format, ...);

/** write format to a file descriptor
 * @param fd file descriptor to write at
 * @param format string containing the format
 * @param ... arguments corresponding to the formats
 * @returns number of characters written to the output
 * OR -1 on error
*/
int my_dprintf(int fd, char *format, ...);

//fspe_t struct for my_printf
//@param fd the output
//@param current_len current number of characters written
//@param width min width
//@param precision max len of str or numbers after the dot
//@param flags string with all flags
//@param len_mod type length modifier
typedef struct fspe_s {
    int fd;
    int current_len;
    int width;
    int precision;
    char flags;
    char len_mod;
}fspe_t;

//reset all values of an fspe struct but fd and current_len
//@param pf fspee_t struct
void reset_pf(fspe_t *pf);
//Read the format of the transformation
//@param pf fspe_t struct
//@param ptr adresse of the current string
//@param list va_list
//@note ptr will be moved and once this function stop, it should be on top
//of the specifier, if there is nothing then the specifier is missing
void make_fspe_mod(fspe_t *pf, char **ptr, va_list list);

//spe_t struct for my_printf
//@param letter the specifier
//@param func the function assigned to specifier
//@note func have to return an int representing the number of characters
//they wrote and take as parameter:
//va_list list, fspe_t *pf
typedef struct spe_s {
    char letter;
    int (*func)(va_list list, fspe_t *pf);
}spe_t;


//------------------------- transformations -------------------------//

/** handle a string transformation
 * @param list va_list
 * @param pf fspe_t struct
 * @returns number of written characters
 * OR -1 on error
 */
int mod_s(va_list list, fspe_t *pf);

/** handle hexadecimal transformation
 * @param list va_list
 * @param pf fspe_t struct
 * @returns number of written characters
 * OR -1 on error
 */
int mod_x(va_list list, fspe_t *pf);

/** handle HEXADECIMAL transformation
 * @param list va_list
 * @param pf fspe_t struct
 * @returns number of written characters
 * OR -1 on error
 */
int mod_big_x(va_list list, fspe_t *pf);

/** handle binary transformation
 * @param list va_list
 * @param pf fspe_t struct
 * @returns number of written characters
 * OR -1 on error
 */
int mod_b(va_list list, fspe_t *pf);

/** handle list of strings transformation
 * @param list va_list
 * @param pf fspe_t struct
 * @returns number of written characters
 * OR -1 on error
 */
int mod_big_s(va_list list, fspe_t *pf);

/** handle decimal transformation
 * @param list va_list
 * @param pf fspe_t struct
 * @returns number of written characters
 * OR -1 on error
 */
int mod_d(va_list list, fspe_t *pf);

//mod_d if is type int
int int_mod_d(va_list list, fspe_t *pf);
//mod_d if is type long int
int long_mod_d(va_list list, fspe_t *pf);
//mod_d if is type long long int
int lli_mod_d(va_list list, fspe_t *pf);

/** handle double transformation
 * @param list va_list
 * @param pf fspe_t struct
 * @returns number of written characters
 * OR -1 on error
 */
int mod_f(va_list list, fspe_t *pf);

/** handle pointer transformation
 * @param list va_list
 * @param pf fspe_t struct
 * @returns number of written characters
 * OR -1 on error
 */
int mod_p(va_list list, fspe_t *pf);

/** handle char transformation
 * @param list va_list
 * @param pf fspe_t struct
 * @returns number of written characters
 * OR -1 on error
 */
int mod_c(va_list list, fspe_t *pf);

//------------------------- utils -------------------------//

/** Add enough padding to reach minimum field width if padding is needed
 * @param length current field width
 * @param pf fspe_t struct
 * @returns number of characters written
 */
int pf_width_handler(int length, fspe_t *pf);

/** add enough '0' to reach the minimum precision if padding is needed
 * @param length length of the number to be written
 * @param pf fspe_t struct
 * @returns length of written characters
 */
int zero_padding(int length, fspe_t *pf);

int pf_putlli(long long int nb, fspe_t *pf);
int pf_putlgi(long int nb, fspe_t *pf);
int pf_putint(int nb, fspe_t *pf);
int pf_putchar(char c, fspe_t *pf);

/** print a + if flag '+' is present
 * @param pf fsep_t struct
 * @returns length of written characters
 */
int print_plus(fspe_t *pf);
#endif /* MA_PRINTF_H */
