# Makefile

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
LIBS = $(shell pkg-config --cflags --libs zlib)

main: main.o
    $(CXX) $(CXXFLAGS) -o $@ $< $(LIBS)

main.o: main.cc main.hh
