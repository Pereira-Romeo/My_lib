# My_Lib a C library 

## A standard C library

This project is a personnal project that i work on during free time to deepen my knowledge about the C standard library and C in general.
Along this project i am also learning how to use github and all its tools.

Every functions in this project has been tested but most likely still has bug as this is only training.

## How to modify this project for your own uses

1. clone and rename this repo to your own
2. add all your .c files to a directory
3. put this directory in lib/my/ and add a header file for your functions in lib/my/headers
4. and finally add this line at the top of the Makefile in lib/my/ : ```SRC += $(wildcard my_dir/*.c)```

for an exemple of how to compile with this library, take a look a the Makefile at the root.

## Known Issues (work in progress)

a lot of the function's descriptions aren't up to date with new standards in the header files

## Coming soon (or atleast, some day in the future)
a new my_printf that uses mallocs, is a lot more speed efficient + a variant that writes in a specified file descriptor
