# A standard C99 library

This project is a personnal project[^1] that i work on during free time to deepen my knowledge about the C standard library and C in general.
Along this project i am also learning how to use github and all its tools.

[^1]: @Doritosbzh also contributed to the my_printf, and the new one in progress.

> [!WARNING]
> Every functions in this project have been tested but most likely still have bugs as this is mostly training.

## table of contents

 - [How to use this library](#how-to-use-this-library).
 - [Known issues](#known-issues-work-in-progress).
 - [Dependencies](#dependencies).
 - [Coming soon](#coming-soon-or-atleast-some-day-in-the-future).


# How to use this library
### Modifying this project for your own uses
1. clone and rename this repo to your own
2. add all your .c files to a directory
3. put this directory in lib/my/ and add a header file for your functions in lib/my/headers
4. and finally add this line at the top of the Makefile in lib/my/ : ```SRC += $(wildcard my_dir/*.c)```

for an exemple of how to compile with this library, take a look a the Makefile at the root.

### Using inside a project
Copy all these files, change the main in main.c to your convenience.\
put your source file inside the src dir and to the SRC var in the Makefile of the root if they are in a sub folder of src (or anywhere else).

The src folder is made for all .c files.\
The include folder is made for all .h files.

# Known Issues (work in progress)

Most of the doc string in the header files are not up to date with new standards

the coding style checker does not work with this repo due to unknown reasons :cry:\
meaning this repo may not fit the coding style perfectly.


# Dependencies

> [!CAUTION]
> this section may not be up to date

<details>
<summary> __external dependencies__ </summary>

my_math is fully independant (except for base_switcher.c, depends on write())

my_mem depends on malloc and free

my_str depends on write (a lot, obviously)
</details>

<details>
<summary name="bruh"> __internal dependencies__ </summary>

my_math is fully_independant (except for base_switcher.c)

the sub libraries my_errno, my_mem and my_bool are used all over this library, do not remove.
</details>

# Coming soon (or atleast, some day in the future)

 - [ ] A new printf (still without mallocs) wich has "my_printf" and "my_dprintf".
 - [ ] Using my_lperror() for all error messages in the library.
 - [ ] Update the docstring in all header files.
 - [ ] Make this readme look better.
