# Definitions for constants
CC=g++
CFLAGS=-I.

.PHONY: clean

all: make clean

# This will create your final output using .o compiled files
make: main.o foobar.o foo.o bar.o file_ops.o
	$(CC) $(CFLAGS) -o main main.o foobar.o foo.o bar.o file_ops.o

foobar.o: foobar.cpp foobar.h
	$(CC) $(CFLAGS) -c foobar.cpp

foo.o: foo.cpp foo.h foobar.h
	$(CC) $(CFLAGS) -c foo.cpp

bar.o: bar.cpp bar.h foobar.h
	$(CC) $(CFLAGS) -c bar.cpp

file_ops.o: file_ops.cpp file_ops.h foobar.h foo.h bar.h
	$(CC) $(CFLAGS) -c file_ops.cpp


# This will compile main.cpp with its dependency
main.o: main.cpp file_ops.h
	$(CC) $(CFLAGS) -c main.cpp

# This will clean or remove compiled files so you can start fresh
clean:
	rm -f *.o *.stackdump tetris 

