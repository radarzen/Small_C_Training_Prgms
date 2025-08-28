# Makefile for NATO Phonetic Alphabet Converter
# Compiler and flags
CC = clang
CFLAGS = -Wall -Wextra -std=c17 -O2
DEBUG_CFLAGS = -Wall -Wextra -std=c17 -g -DDEBUG

# Program name
PROGRAM = nato

# Source files
SOURCES = nato.c nato_source.c nato_help.c
OBJECTS = $(SOURCES:.c=.o)

# Header files
HEADERS = nato.h

# Default target
all: $(PROGRAM)

# Build the program
$(PROGRAM): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROGRAM)

# Compile source files to object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Debug build
debug: CFLAGS = $(DEBUG_CFLAGS)
debug: $(PROGRAM)

# Clean build artifacts
clean:
	rm -f $(OBJECTS) $(PROGRAM)

# Install the program (requires sudo for system-wide install)
install: $(PROGRAM)
	sudo cp $(PROGRAM) /usr/local/bin/
	sudo chmod +x /usr/local/bin/$(PROGRAM)

# Uninstall the program
uninstall:
	sudo rm -f /usr/local/bin/$(PROGRAM)

# Show help
help:
	@echo "Available targets:"
	@echo "  all       - Build the program (default)"
	@echo "  debug     - Build with debug symbols"
	@echo "  clean     - Remove build artifacts"
	@echo "  install   - Install to /usr/local/bin (requires sudo)"
	@echo "  uninstall - Remove from /usr/local/bin (requires sudo)"
	@echo "  help      - Show this help message"

# Phony targets
.PHONY: all debug clean install uninstall help

# Dependencies
nato.o: nato.c nato.h
nato_source.o: nato_source.c nato.h
nato_help.o: nato_help.c nato.h
