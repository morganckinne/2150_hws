# Makefile for CS 2150 inlab 11

# Defines the C++ compiler we'll be using
CXX = clang++

CXXFLAGS = -Wall -g -O2 -std=c++11

OBJECTS = puzzle.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	doxygen

clean:
	-rm -f *.o *~
