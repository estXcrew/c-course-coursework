# Compiler
CC = gcc

# Compiler flags
CFLAGS = -std=c90 -Wall -Wextra -pedantic -lm -DLIVE=1

# Source files
SOURCES = vaihto.c

# Output executable
OUTPUT = o

# Target for building the executable
all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) -o $(OUTPUT).elf $(SOURCES) 
	./$(OUTPUT).elf 

# Clean target to remove the executable
clean:
	rm -f $(OUTPUT)

.PHONY: all clean
