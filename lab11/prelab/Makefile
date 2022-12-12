# Makefile for CS 2150 prelab 11

# Defines the C++ compiler we'll be using
CXX = clang++

CXXFLAGS = -Wall -g -O2 -std=c++11

OBJECTS = topological.o middleearth.o 

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	doxygen

clean:
	-rm -f *.o *~
