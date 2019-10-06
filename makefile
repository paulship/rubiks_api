MAKEFLAGS += --no-builtin-rules

# Executables
CC := cc

# List of sources
C_SOURCES = ./rubiks.c \
            ./rubiks_display.c \
            ./rubiks_move.c \
            ./main.c

# The list of objects is the same as sources with '.c' changes to '.o'
OBJECTS = $(C_SOURCES:.c=.o)

# Rule for the final executable
rubiks.out : $(OBJECTS)
	$(CC) $(OBJECTS) -o rubiks.out

# General rule to turn any.c to any.o
%.o : %.c makefile
	$(CC) -c $(<) -o $(<:.c=.o) -Wall -Wpedantic -Wextra

# Cleanup - removes all object files and the output file
clean :
	rm $(OBJECTS)
	rm rubiks.out


