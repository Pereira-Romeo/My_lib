# A standard C99 library

This project is a personnal project[^1] that i work on during free time to deepen my knowledge about the C standard library and C in general.
Along this project i am also learning how to use github and all its tools.

[^1]: @Doritosbzh also contributed a bit.

> [!WARNING]
> Every functions in this project have been tested but most likely still have bugs as this is mostly training.

## table of contents

 - How to use this library: [Link Text](#how-to-use-this-library).
 - Known issues: [Link Text](#known-issues-work-in-progress).
 - Dependencis: [Link Text](#dependencies).
 - Coming soon: [Link Text](#coming-soon-or-atleast-some-day-in-the-future).


# How to use this library
## How to modify this project for your own uses
1. clone and rename this repo to your own
2. add all your .c files to a directory
3. put this directory in lib/my/ and add a header file for your functions in lib/my/headers
4. and finally add this line at the top of the Makefile in lib/my/ : ```SRC += $(wildcard my_dir/*.c)```

for an exemple of how to compile with this library, take a look a the Makefile at the root.


# Known Issues (work in progress)

Most of the doc string in the header files are not up to date with new standards

the coding style checker does not work with this repo for some reason, but it does work when copying this repo inside another project, i do not know what the error is.
I tried adding the coding style check to git actions but these ones crash aswell...


# Dependencies
## external dependencies (this section is probably not up to date)

my_math is fully independant (except for base_switcher.c, depends on write())

my_mem depends on malloc and free

my_str depends on write (a lot, obviously)

## internal dependencies (this section is probably not up to date)

my_math is fully_independant (except for base_switcher.c)

the sub libraries my_errno, my_mem and my_bool are used all over this library, do not remove.


# Coming soon (or atleast, some day in the future)

 - [ ] A new printf (still without mallocs) wich has "my_printf" and "my_dprintf".
 - [ ] Using my_lperror() for all error messages in the library.
 - [ ] Update the docstring in all header files.
 - [ ] Make this readme look better.
