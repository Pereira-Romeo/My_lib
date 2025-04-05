/*
** EPITECH PROJECT, 2025
** my_lib_off
** File description:
** my_perror
*/

#include "../headers/my_errno.h"

static
int my_strlen(char *str)
{
    char *ptr = str;

    while (ptr && *ptr) {
        ptr++;
    }
    return ptr - str;
}

//list of all error messages and their sizes.
//the error value corresponds to the index of the message in this list
//the error values should be macros from errno.h
static
const errs_t error_tab[NB_ERR_MESS + 1] =
{
    {"Success.\n", 9},
    {"Operation not permitted.\n", 25},
    {"No such file or directory.\n", 27},
    {"No such process.\n", 17},
    {"Interrupted system call.\n", 25},
    {"Input/output error.\n", 20},
    {"No such device or address.\n", 27},
    {"Argument list too long.\n", 24},
    {"Exec format error.\n", 19},
    {"Bad file descriptor.\n", 21},
    {"No child processes.\n", 20},
    {"Resource temporarily unavailable.\n", 34},
    {"Cannot allocate memory.\n", 24},
    {"Permission denied.\n", 19},
    {"Bad address.\n", 13},
    {"Block device required.\n", 23},
    {"Device or resource busy.\n", 25},
    {"File exists.\n", 13},
    {"Invalid cross-device link.\n", 27},
    {"No such device.\n", 16},
    {"Not a directory.\n", 17},
    {"Is a directory.\n", 16},
    {"Invalid argument.\n", 18},
    {"Too many open files in system.\n", 31},
    {"Too many open files.\n", 21},
    {"Inappropriate ioctl for device.\n", 32},
    {"Text file busy.\n", 16},
    {"File too large.\n", 16},
    {"No space left on device.\n", 25},
    {"Illegal seek.\n", 14},
    {"Read-only file system.\n", 23},
    {"Too many links.\n", 16},
    {"Broken pipe.\n", 13},
    {"Numerical argument out of domain.\n", 34},
    {"Numerical result out of range.\n", 31},
    {"Resource deadlock avoided.\n", 27},
    {"File name too long.\n", 20},
    {"No locks available.\n", 20},
    {"Function not implemented.\n", 26},
    {"Directory not empty.\n", 21},
    {"Too many levels of symbolic links.\n", 35},
    {"Unknown error 41.\n", 18},
    {"No message of desired type.\n", 28},
    {"Identifier removed.\n", 20},
    {"Channel number out of range.\n", 29},
    {"Level 2 not synchronized.\n", 26},
    {"Level 3 halted.\n", 16},
    {"Level 3 reset.\n", 15},
    {"Link number out of range.\n", 26},
    {"Protocol driver not attached.\n", 30},
    {"No CSI structure available.\n", 28},
    {"Level 2 halted.\n", 16},
    {"Invalid exchange.\n", 18},
    {"Invalid request descriptor.\n", 28},
    {"Exchange full.\n", 15},
    {"No anode.\n", 10},
    {"Invalid request code.\n", 22},
    {"Invalid slot.\n", 14},
    {"Unknown error 58.\n", 18},
    {"Bad font file format.\n", 22},
    {"Device not a stream.\n", 21},
    {"No data available.\n", 19},
    {"Timer expired.\n", 15},
    {"Out of streams resources.\n", 26},
    {"Machine is not on the network.\n", 31},
    {"Package not installed.\n", 23},
    {"Object is remote.\n", 18},
    {"Link has been severed.\n", 23},
    {"Advertise error.\n", 17},
    {"Srmount error.\n", 15},
    {"Communication error on send.\n", 29},
    {"Protocol error.\n", 16},
    {"Multihop attempted.\n", 20},
    {"RFS specific error.\n", 20},
    {"Bad message.\n", 13},
    {"Value too large for defined data type.\n", 39},
    {"Name not unique on network.\n", 28},
    {"File descriptor in bad state.\n", 30},
    {"Remote address changed.\n", 24},
    {"Can not access a needed shared library.\n", 40},
    {"Accessing a corrupted shared library.\n", 38},
    {".lib section in a.out corrupted.\n", 33},
    {"Attempting to link in too many shared libraries.\n", 49},
    {"Cannot exec a shared library directly.\n", 39},
    {"Invalid or incomplete multibyte or wide character.\n", 51},
    {"Interrupted system call should be restarted.\n", 45},
    {"Streams pipe error.\n", 20},
    {"Too many users.\n", 16},
    {"Socket operation on non-socket.\n", 32},
    {"Destination address required.\n", 30},
    {"Message too long.\n", 18},
    {"Protocol wrong type for socket.\n", 32},
    {"Protocol not available.\n", 24},
    {"Protocol not supported.\n", 24},
    {"Socket type not supported.\n", 27},
    {"Operation not supported.\n", 25},
    {"Protocol family not supported.\n", 31},
    {"Address family not supported by protocol.\n", 42},
    {"Address already in use.\n", 24},
    {"Cannot assign requested address.\n", 33},
    {"Network is down.\n", 17},
    {"Network is unreachable.\n", 24},
    {"Network dropped connection on reset.\n", 37},
    {"Software caused connection abort.\n", 34},
    {"Connection reset by peer.\n", 26},
    {"No buffer space available.\n", 27},
    {"Transport endpoint is already connected.\n", 41},
    {"Transport endpoint is not connected.\n", 37},
    {"Cannot send after transport endpoint shutdown.\n", 47},
    {"Too many references: cannot splice.\n", 36},
    {"Connection timed out.\n", 22},
    {"Connection refused.\n", 20},
    {"Host is down.\n", 14},
    {"No route to host.\n", 18},
    {"Operation already in progress.\n", 31},
    {"Operation now in progress.\n", 27},
    {"Stale file handle.\n", 19},
    {"Structure needs cleaning.\n", 26},
    {"Not a XENIX named type file.\n", 29},
    {"No XENIX semaphores available.\n", 31},
    {"Is a named type file.\n", 22},
    {"Remote I/O error.\n", 18},
    {"Disk quota exceeded.\n", 21},
    {"No medium found.\n", 17},
    {"Wrong medium type.\n", 19},
    {"Operation canceled.\n", 20},
    {"Required key not available.\n", 28},
    {"Key has expired.\n", 17},
    {"Key has been revoked.\n", 22},
    {"Key was rejected by service.\n", 29},
    {"Owner died.\n", 12},
    {"State not recoverable.\n", 23},
    {"Operation not possible due to RF-kill.\n", 39},
    {"Memory page has hardware error.\n", 32}
};

int my_perror(char *str, int err, int val)
{
    if (err >= 0 && err <= NB_ERR_MESS) {
        if (str) {
            write(STDERR_FILENO, str, my_strlen(str));
            write(STDERR_FILENO, ": ", 2);
        }
        write(STDERR_FILENO, error_tab[err].e_mess,
        error_tab[err].mess_size);
    }
    return val;
}

int my_lperror(char *str, int err, int val)
{
    if (LIB_PRINT_ERROR)
        return my_perror(str, err, val);
    return val;
}
