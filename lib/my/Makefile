##
## EPITECH PROJECT, 2024
## makefile d10
## File description:
## better builder
##

# SRC := $(wildcard my_errno/*.c)
# SRC += $(wildcard my_file/*.c)
# SRC += $(wildcard my_linked_list/*.c)
# SRC += $(wildcard my_math/*.c)
# SRC += $(wildcard my_mem/*.c)
# SRC += $(wildcard my_printf/*.c)
# SRC += $(wildcard my_str/*.c)
# SRC += $(wildcard my_tab/*.c)

# OBJ = $(SRC:.c=.o)

# CFLAGS = -Wall -Wextra

# NAME = libmy.a

# all: $(NAME)

# $(NAME):    $(OBJ)
# 	ar rc $(NAME) $(OBJ)
# 	cp libmy.a ../
# 	mkdir -p ../../include
# 	cp -f headers/*.h ../../include/

# clean:
# 	rm -f $(OBJ)

# fclean: clean
# 	rm -f ../libmy.a
# 	rm -f $(NAME)

# re: fclean all

##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## General Makefile
## https://www.gnu.org/software/make/manual/make.html
##


NAME = libmy.a

##================================================================##
##================= Source Files =================================##
##================================================================##
SRCDIR = ./

SRC := $(wildcard $(SRCDIR)/my_errno/*.c)
SRC += $(wildcard $(SRCDIR)/my_file/*.c)
SRC += $(wildcard $(SRCDIR)/my_linked_list/*.c)
SRC += $(wildcard $(SRCDIR)/my_math/*.c)
SRC += $(wildcard $(SRCDIR)/my_mem/*.c)
SRC += $(wildcard $(SRCDIR)/my_printf/*.c)
SRC += $(wildcard $(SRCDIR)/my_str/*.c)
SRC += $(wildcard $(SRCDIR)/my_tab/*.c)

##================================================================##
##================= Object Files ===================================
##================================================================##
BUILDDIR = ../../.build/lib

OBJ := $(SRC:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)


##================================================================##
##================= Compiling options ============================##
##================================================================##
#.c compiler, inherited from main makefile
CC = $(MY_CC)

#generic flags
CFLAGS = -Wall -Wextra \
-Wformat-nonliteral -Wcast-align -Wpointer-arith  \
-Wmissing-declarations -Winline -Wundef \
-Wcast-qual -Wshadow -Wwrite-strings -Wno-unused-parameter \
-Wfloat-equal -pedantic

FLAGS = $(CFLAGS) $(LDFLAGS)



##================================================================##
##================= Rules ========================================##
##================================================================##

.PHONY: all
all: $(NAME)

.PHONY: buildprint
buildprint:
# this if runs at parse time and not run time (but it don't matter for the use)
ifeq ("$(wildcard ./$(NAME))","")
	@ echo "$(PBC)Building $(NAME):$(PRESET)";
else
	@ echo "$(PBC)Nothing to build for $(NAME).$(PRESET)"
endif


$(NAME): $(OBJ)
	@ ar rc $@ $(OBJ) || \
		( echo "$(PBC)[$(PCR)KO$(PBNC)]$(PRESET) $@"; \
		exit 1 )
	@ echo "$(PBC)[$(PCG)OK$(PBNC)]$(PRESET) $@"
	@ cp libmy.a ../
	@ cp headers/*.h ../../include/

$(BUILDDIR)/%.o: $(SRCDIR)/%.c | buildprint
	@ mkdir -p $(dir $@)
	@ $(CC) -o $@ -c $< || \
	( echo "    $(PBC)[$(PCR)KO$(PBNC)]$(PRESET) $(subst $(BUILDDIR)/,,$@)"; \
	exit 1 )
	@ echo "    $(PBC)[$(PCG)OK$(PBNC)]$(PRESET) $(subst $(BUILDDIR)/,,$@)"


.PHONY: clean
clean:
	@ rm -f $(OBJ)


.PHONY: fclean
fclean: clean
	@ echo "$(PBCP)Deleting:$(PRESET) $(NAME)"
	@ rm -f $(NAME)
	@ rm -f ../$(NAME)

.PHONY: re
re:     fclean all

##================================================================##
##================= Fancy Stuff ==================================##
##================================================================##
MAKEFLAGS += --no-print-directory

#print in bold, keep colors
PBC = \033[1m
#print in bold, cancel colors
PBNC = $(PRESET)$(PBC)
#print green
PCG = \033[32m
#print red
PCR = \033[31m
#print bold purple
PBCP = $(PBNC)\033[35m
#print reset everything
PRESET = \033[0m
