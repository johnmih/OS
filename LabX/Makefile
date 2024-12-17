# Compiler
CC = gcc

# Compilation flags
CFLAGS = -Wall -g

# Source files
SOURCES = code1.c code2.c code3.c code4.c code5.c

# Binaries directory
BIN_DIR = bin

# Generate binary names based on source files
BINARIES = $(patsubst %.c,$(BIN_DIR)/%,$(SOURCES))

# Default target
all: $(BINARIES)

# Rule to build binaries
$(BIN_DIR)/%: %.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

# Clean target to remove binaries
clean:
	rm -rf $(BIN_DIR)

# Phony targets
.PHONY: all clean
