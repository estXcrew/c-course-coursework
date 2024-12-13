# Compiler
CC = gcc

# Compiler flags
CFLAGS = -std=c90 -Wall -Wextra -pedantic

# Source files
SOURCES = unsigned.c

# Output executable
OUTPUT = o

# Target for building the executable
all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) -o $(OUTPUT).elf $(SOURCES)

# Clean target to remove the executable
clean:
	rm -f $(OUTPUT)

.PHONY: all clean
