##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## general Makefile
##

SRC := main.c
SRC += $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

NAME = main

CFLAGS = -Wall -Wextra -iquote include

LDFLAGS = -L lib/ -lmy -lm

CLEAR_LIB_CMD := ./lib/my/clear_lib.sh


all:    mylib $(NAME)

mylib:
	make -C lib/my all

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)
	mkdir -p .build
	mv $(OBJ) .build/

# Deletes any unused dependencie from the lib (use at end of project)
clear_lib:  # clear all not needed lib files
	$(CLEAR_LIB_CMD)

init_clear: # only remove license and readme
	$(CLEAR_LIB_CMD) --init

last_clear: # clear_lib + delete clear script o7
	$(CLEAR_LIB_CMD) --last

clean:
	make -C lib/my fclean
	rm -f .build/*

fclean: clean
	rm -f libmy.a
	rm -f $(NAME)

re:     fclean all
