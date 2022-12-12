#Morgan Kinne lab section 104
#Makefile for Hash Lab(6)

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g

a.out: timer.o wordPuzzle.o hashTable.o
	$(CXX) $(DEBUG) timer.o wordPuzzle.o hashTable.o -o a.out
	@echo "Pizza is Hot and Ready!"

timer.o: timer.cpp timer.h

wordPuzzle.o: wordPuzzle.cpp

hashTable.o: hashTable.cpp hashTable.h

.PHONY: clean
clean:
	-rm -f *.o a.out
