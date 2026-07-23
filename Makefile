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

#path of your file containing the main
EXECSRC = $(SRCDIR)/main$(EXT)

# SRC := $(wildcard $(SRCDIR)/*$(EXT))
SRC := $(filter-out $(EXECSRC), $(wildcard $(SRCDIR)/*$(EXT)))

#criterion test sources
TESTSRC = $(wildcard $(TESTDIR)/*$(EXT))
TESTSRC += $(wildcard $(TESTDIR)/argHandler_class/*$(EXT))
TESTSNAME = tests.bin
TESTDIR = tests

##================================================================##
##================= Object Files ===================================
##================================================================##
BUILDDIR = .build

OBJ := $(SRC:$(SRCDIR)/%$(EXT)=$(BUILDDIR)/%.o)
EXECOBJ = $(EXECSRC:$(SRCDIR)/%$(EXT)=$(BUILDDIR)/%.o)
TESTOBJ = $(TESTSRC:$(TESTDIR)/%$(EXT)=$(BUILDDIR)/tests/%.o)

##================================================================##
##================= Compiling options ============================##
##================================================================##
#.c compiler
CC = gcc

#.cpp compiler
CXX = g++

#generic library flags
LDFLAGS = -luuid

#set to true to include library (INCLUDE_LIB = true)
#leave empty otherwise (include_lib =)
INCLUDE_LIB = true

#mylib_flag
MY_LIB = -L lib/ -lmy
ifeq ($(INCLUDE_LIB), true)
	LDFLAGS += $(MY_LIB)
endif

#generic error flags
CFLAGS = -Wall -Wextra -Wformat-nonliteral -Wcast-align -Wpointer-arith  \
-Wmissing-declarations -Winline -Wundef \
-Wcast-qual -Wshadow -Wwrite-strings -Wno-unused-parameter \
-Wfloat-equal -pedantic

#generic .cpp flags
CXXFLAGS = -std=c++20 -fno-gnu-unique

ifeq ($(EXT), .c)
#.c specific options
	COMPILER = $(CC)
	CFLAGS += -iquote include/
	LDFLAGS +=
	FLAGS = $(CFLAGS)
else
#.cpp specific options
	COMPILER = $(CXX)
	CFLAGS += -Woverloaded-virtual
	CFLAGS += -Iinclude/
	LDFLAGS +=
	FLAGS = $(CFLAGS) $(CXXFLAGS)
endif


##================================================================##
##================= Rules ========================================##
##================================================================##

all: mylib $(NAME)

.PHONY: mylib
mylib:
	@ [ "$(INCLUDE_LIB)" = "true" ] && {\
		export MY_CC=$(CC); make -C lib/my; \
		echo ""; \
	} || {\
		:;\
	}


.PHONY: buildprint
buildprint:
	@ [ -f $(NAME) ] && { \
		echo "$(PBC)Nothing to build for $(NAME).$(PRESET)"; \
	} || { \
		echo "$(PBC)Building $(NAME):$(PRESET)"; \
	}

$(NAME): $(OBJ) $(EXECOBJ)
	@ $(COMPILER) -o $@ $(EXECOBJ) $(OBJ) $(FLAGS) $(LDFLAGS) || \
	( echo "$(PBC)[$(PCR)KO$(PBNC)]$(PRESET) $@"; \
	exit 1 )
	@ echo "$(PBC)[$(PCG)OK$(PBNC)]$(PRESET) $@"

$(BUILDDIR)/%.o: $(SRCDIR)/%$(EXT) | buildprint
	@ mkdir -p $(dir $@)
	@ $(COMPILER) $(FLAGS) -o $@ -c $< || \
	( echo "    $(PBC)[$(PCR)KO$(PBNC)]$(PRESET) $(subst $(BUILDDIR)/,,$@)"; \
	exit 1 )
	@ echo "    $(PBC)[$(PCG)OK$(PBNC)]$(PRESET) $(subst $(BUILDDIR)/,,$@)"

$(BUILDDIR)/tests/%.o: $(TESTDIR)/%$(EXT)
	@ mkdir -p $(dir $@)
	@ $(COMPILER) $(FLAGS) -o $@ -c $< || \
	( echo "    $(PBC)[$(PCR)KO$(PBNC)]$(PRESET) $(subst $(BUILDDIR)/,,$@)"; \
	exit 1 )
	@ echo "    $(PBC)[$(PCG)OK$(PBNC)]$(PRESET) $(subst $(BUILDDIR)/,,$@)"


.PHONY: clean
clean:
	@ [ "$(INCLUDE_LIB)" = "true" ] && {\
		make -C lib/my clean; \
	} || {\
		:;\
	}
	@ rm -f $(OBJ) $(EXECOBJ) $(TESTSNAME) $(TESTOBJ)
	@ rm -fr $(BUILDDIR)


.PHONY: fclean
fclean: clean
	@ [ "$(INCLUDE_LIB)" = "true" ] && {\
		make -C lib/my fclean; \
	} || {\
		:;\
	}
	@ echo "$(PBCP)Deleting:$(PRESET) $(NAME)"
	@ rm -f $(NAME)

.PHONY: delspacing
delspacing:
	@ [ "$(INCLUDE_LIB)" = "true" ] && {\
		echo ""; \
		echo ""; \
	} || {\
		echo "";\
	}

.PHONY: re
re:     fclean delspacing all

.PHONY: tests_run
tests_run: FLAGS += -O0 -g --coverage
tests_run: LDFLAGS += -lcriterion
tests_run: tests.bin
	@ echo ""
	@ ./tests.bin || exit 0
	@ echo ""
	@ gcovr -r . --exclude 'tests/.*'

$(TESTSNAME): $(OBJ) $(TESTOBJ)
	@ $(COMPILER) -o $@ $(TESTOBJ) $(OBJ) $(FLAGS) $(LDFLAGS) || \
	( echo "$(PBC)[$(PCR)KO$(PBNC)]$(PRESET) $@"; \
	exit 1 )
	@ echo "$(PBC)[$(PCG)OK$(PBNC)]$(PRESET) $@"

.PHONY: debug
debug: CFLAGS += -DDEBUG_MODE
debug: re


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
