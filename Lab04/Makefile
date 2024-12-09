# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Source files
SOURCES = example1.c example2.c example3.c example4.c example5.c

# Default target (build all executables)
all: example1 example2 example3 example4 example5

# Targets for each program
example1: example1.o
	$(CC) $(CFLAGS) -o $@ example1.o

example2: example2.o
	$(CC) $(CFLAGS) -o $@ example2.o

example3: example3.o
	$(CC) $(CFLAGS) -o $@ example3.o

example4: example4.o
	$(CC) $(CFLAGS) -o $@ example4.o

example5: example5.o
	$(CC) $(CFLAGS) -o $@ example5.o

# Pattern rule to compile .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f *.o example1 example2 example3 example4 example5
