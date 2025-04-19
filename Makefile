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

all:    mylib $(NAME)

mylib:
	make -C lib/my all

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
	make -C lib/my fclean
	rm -f $(OBJ)

fclean: clean
	rm -f libmy.a
	rm -f $(NAME)

re:     fclean all
