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

CLEAR_INIT_CMD := ./lib/my/clear_lib.sh --init #rm license & readme

all:    mylib $(NAME)

mylib:
	make -C lib/my all

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

# Deletes any unused dependencie from the lib (use at end of project)
clear_lib:
	$(CLEAR_LIB_CMD)

init_clear:
	$(CLEAR_INIT_CMD)

clean:
	make -C lib/my fclean
	rm -f $(OBJ)

fclean: clean
	rm -f libmy.a
	rm -f $(NAME)

re:     fclean all
