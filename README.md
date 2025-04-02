# My_Lib a C library 

## A standard C99 library

This project is a personnal project that i work on during free time to deepen my knowledge about the C standard library and C in general.
Along this project i am also learning how to use github and all its tools.

Every functions in this project has been tested but most likely still has bug as this is only training. (ok maybe i'm trying to hard on some but it's fun)

## How to modify this project for your own uses

1. clone and rename this repo to your own
2. add all your .c files to a directory
3. put this directory in lib/my/ and add a header file for your functions in lib/my/headers
4. and finally add this line at the top of the Makefile in lib/my/ : ```SRC += $(wildcard my_dir/*.c)```

for an exemple of how to compile with this library, take a look a the Makefile at the root.

## Known Issues (work in progress)

a lot of the function's descriptions aren't up to date with new standards in the header files

## external dependencies (this section is probably not up to date)

my_math is fully independant (except for base_switcher.c, depends on write())

my_mem depends on malloc and free

my_str depends on write (a lot, obviously)

## internal dependencies (this section is probably not up to date)

my_math is fully_independant (except for base_switcher.c)

the sub libraries my_errno, my_mem and my_bool are used all over this library, do not remove.


## Coming soon (or atleast, some day in the future)
A new my_printf still without mallocs because why would i want to waste time allocating mem.

The use my_lperror() everywhere in my library to centralize the error printing, also there is a define that can be set to 0 if you don't want the library to print any error message (this will take effect only when i'll add my_lperror everywhere)
