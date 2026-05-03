##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## General Makefile
## https://www.gnu.org/software/make/manual/make.html
##


NAME = main

#supported extensions: .c/.cpp
EXT = .c

##================================================================##
##================= Source Files =================================##
##================================================================##
SRCDIR = src

SRC := $(wildcard $(SRCDIR)/*$(EXT))


##================================================================##
##================= Object Files ===================================
##================================================================##
BUILDDIR = .build

OBJ := $(SRC:$(SRCDIR)/%$(EXT)=$(BUILDDIR)/%.o)


##================================================================##
##================= Compiling options ============================##
##================================================================##
#.c compiler
CC = gcc

#.cpp compiler
CXX = g++

#generic error flags
CFLAGS = -Wall -Wextra -Wformat-nonliteral -Wcast-align -Wpointer-arith  \
-Wmissing-declarations -Winline -Wundef \
-Wcast-qual -Wshadow -Wwrite-strings -Wno-unused-parameter \
-Wfloat-equal -pedantic

#generic library flags
LDFLAGS = -L lib/ -lmy -lm

#generic .cpp flags
CXXFLAGS = -std=c++20 -fno-gnu-unique

ifeq ($(EXT), .c)
#.c specific options
	COMPILER = $(CC)
	CFLAGS += -iquote include/
	LDFLAGS +=
	FLAGS = $(CFLAGS) $(LDFLAGS)
else
#.cpp specific options
	COMPILER = $(CXX)
	CFLAGS += -Woverloaded-virtual
	CFLAGS += -Iinclude/
	LDFLAGS +=
	FLAGS = $(CFLAGS) $(LDFLAGS) $(CXXFLAGS)
endif


##================================================================##
##================= Rules ========================================##
##================================================================##

all: mylib $(NAME)

.PHONY: mylib
mylib:
	@ make -C lib/my
	@ echo ""


.PHONY: buildprint
buildprint:
ifeq ("$(wildcard ./$(NAME))","")
	@ echo "$(PBC)Building $(NAME):$(PRESET)";
else
	@ echo "$(PBC)Nothing to build for $(NAME).$(PRESET)"
endif


$(NAME): $(OBJ)
	@ $(COMPILER) -o $@ $(OBJ) $(FLAGS) || \
		( echo "$(PBC)[$(PCR)KO$(PBNC)]$(PRESET) $@"; \
		exit 1 )
	@ echo "$(PBC)[$(PCG)OK$(PBNC)]$(PRESET) $@"

$(BUILDDIR)/%.o: $(SRCDIR)/%$(EXT) | buildprint
	@ mkdir -p $(dir $@)
	@ $(COMPILER) $(FLAGS) -o $@ -c $< || \
		( echo "    $(PBC)[$(PCR)KO$(PBNC)]$(PRESET) $(subst $(BUILDDIR)/,,$@)"; \
		exit 1 )
	@ echo "    $(PBC)[$(PCG)OK$(PBNC)]$(PRESET) $(subst $(BUILDDIR)/,,$@)"


.PHONY: clean
clean:
	@ make -C lib/my clean
	@ rm -f $(OBJ)


.PHONY: fclean
fclean: clean
	@ make -C lib/my fclean
	@ echo ""
	@ echo "$(PBCP)Deleting:$(PRESET) $(NAME)"
	@ rm -f $(NAME)

.PHONY: delspacing
delspacing:
	@ echo ""
	@ echo ""

.PHONY: re
re:     fclean delspacing all

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
