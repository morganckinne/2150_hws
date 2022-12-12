# Makefile for CS 2150 prelab 10

# Defines the C++ compiler we'll be using
CXX = clang++

CXXFLAGS = -Wall -g

OBJECTS = heapnode.o heap.o huffmanenc.o hufftree.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-rm -f *.o *~
