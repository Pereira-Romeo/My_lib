# A standard C99 library

 ![coding style check](https://github.com/Pereira-Romeo/My_lib/actions/workflows/coding_style_check.yml/badge.svg)

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
 - [Manuals](#man-my_lib).


# How to use this library

### Modifying this project for your own uses

1. clone this repo and copy the files to your workspace/directory
2. add all your .c files to a directory
3. put this directory in lib/my/ and add a header file for your functions in lib/my/headers
4. and finally add to this [Makefile](./lib/my/Makefile) in lib/my/ : ```SRC += $(wildcard [your_dir]/*.c)```

    ```
    SRC := $(wildcard my_errno/*.c)
    SRC += $(wildcard my_file/*.c)
    SRC += $(wildcard my_linked_list/*.c)
    SRC += $(wildcard my_math/*.c)
    SRC += $(wildcard my_mem/*.c)
    SRC += $(wildcard my_printf/*.c)
    SRC += $(wildcard my_str/*.c)
    SRC += $(wildcard my_tab/*.c)
    SRC += $(wildcard [your_dir]/*.c) <- Here

    OBJ = $(SRC:.c=.o)
    ```

for an exemple of how to compile with this library, take a look at this [Makefile](./Makefile) at the root.

### Using inside a project

Copy all these files, change the main in main.c to your convenience.\
Put your source files inside the src dir and to the SRC var in the Makefile at the root if they are in a sub folder of src (or anywhere else).

The src folder is made for all .c files.\
The include folder is made for all .h files.

# Known Issues (work in progress)

Most of the doc string in the header files are not up to date with new standards

The coding style checker is fixed!... nah i'm joking, it's still broken cuz why would they fix their work... anyway, found what's causing it to die and put it in comment, it's in test/my_perror_tests.c (wich are not up to date with new version of my_errno lib anyway).


# Dependencies

> [!CAUTION]
> this section may not be up to date

<details>
<summary> external dependencies </summary>

my_math is fully independant (except for base_switcher.c, depends on write())

my_mem depends on malloc and free

my_str depends on write (a lot, obviously)

</details>

<details>
<summary> internal dependencie </summary>

my_math is fully_independant (except for base_switcher.c)

the sub libraries my_errno, my_mem and my_bool are used all over this library, do not remove.
</details>

# Coming soon (or atleast, some day in the future)

Ticked items are _regularly_ worked on (as regularly as my free time and will allows)\
Unticked items are _occasionaly_ worked on.

 - [x] New conversions to [my_printf](https://github.com/Pereira-Romeo/my_printf/).
 - [x] Using my_lperror() for all error messages in the library.
 - [ ] Update the docstring in all header files.
 - [ ] Make this readme look better.
 - [ ] Manuals for each sub-lib of My_lib.

# Man My_lib

 - [my_printf lib](https://github.com/Pereira-Romeo/my_printf/blob/main/README.md).