##
## EPITECH PROJECT, 2024
## makefile d10
## File description:
## better builder
##

SRC := $(wildcard my_errno/*.c)
SRC += $(wildcard my_file/*.c)
SRC += $(wildcard my_linked_list/*.c)
SRC += $(wildcard my_math/*.c)
SRC += $(wildcard my_mem/*.c)
SRC += $(wildcard my_printf/*.c)
SRC += $(wildcard my_str/*.c)
SRC += $(wildcard my_tab/*.c)

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra

NAME = libmy.a

all: $(NAME)

$(NAME):    $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp libmy.a ../
	mkdir -p ../../include
	cp -f headers/*.h ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../libmy.a
	rm -f $(NAME)

re: fclean all
