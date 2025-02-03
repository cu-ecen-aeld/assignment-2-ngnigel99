CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Check if CROSS_COMPILE is specified
ifdef CROSS_COMPILE
	CC = $(CROSS_COMPILE)gcc
endif

# Default target to build the writer application
all: writer

# Rule to build the writer application
writer: writer.o
	$(CC) $(CFLAGS) -o writer writer.o

# Rule to compile the writer.c file
writer.o: writer.c
	$(CC) $(CFLAGS) -c writer.c

# Clean target to remove the writer application and all .o files
clean:
	rm -f writer writer.o
