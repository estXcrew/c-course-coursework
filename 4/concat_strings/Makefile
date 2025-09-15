SOURCES = $(wildcard *.c)# Compiler
CC = gcc

# Compiler flags
CFLAGS = -std=c90 -Wall -Wextra -pedantic -lm -DLIVE=1

# Source files
SOURCES = $(wildcard *.c)

# Output executable
OUTPUT = o

# Target for building the executable
all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) -o $(OUTPUT).elf $(SOURCES) 
	./$(OUTPUT).elf yksi kaksi kolme neljä viisi kuusi seitsemän kahdeksan

# Clean target to remove the executable
clean:
	rm -f $(OUTPUT)

.PHONY: all clean
