# Compiler

CC = clang

#This makes it so the compiler shows all warning messages

CFLAGS = -Wall

# Source files

SRC = Project2.c

#Generates the .c file to an object .o file

OBJ = $(SRC:.c=.o)

#Names the exe file created

EXEC = Project2

# Default target to build the program

all: $(EXEC)

# Rule to link object files and create the executable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJ) $(EXEC)
