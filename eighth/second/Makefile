CC = g++
CFLAGS = -Wall -std=c++11
LIBS = $(shell pkg-config --libs zlib)
INCLUDES = $(shell pkg-config --cflags zlib)

all: my_program

my_program: main.o
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

main.o: main.cc main.hh
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

clean:
	rm -f my_program main.o
