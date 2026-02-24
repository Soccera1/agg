# Compiler and flags
CC = gcc
EXTRA_CFLAGS ?=
CFLAGS ?= -Wall -Wextra -std=c99 -pedantic -O3 -flto $(EXTRA_CFLAGS)
LDFLAGS ?= -s
DEBUG_FLAGS = -g -DDEBUG

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Source files
SOURCES = $(SRCDIR)/agg.c
OBJECTS = $(OBJDIR)/agg.o
TARGET = $(BINDIR)/agg

# Default target
all: $(TARGET)

# Create directories if they don't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Link executable
$(TARGET): $(OBJECTS) | $(BINDIR)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

# Debug build
debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET)

# Clean build artifacts
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Install (copy to /usr/local/bin)
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

# Uninstall
uninstall:
	rm -f /usr/local/bin/agg

# Phony targets
.PHONY: all debug clean run install uninstall
