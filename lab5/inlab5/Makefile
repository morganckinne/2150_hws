# This is a comment
#Morgan Kinne lab section ?

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

a.out: BinaryNode.o BinarySearchTree.o BSTPathTest.o
	$(CXX) $(DEBUG) BinaryNode.o BinarySearchTree.o BSTPathTest.o -o a.out
	@echo "Pizza is Hot and Ready!"

BinaryNode.o: BinaryNode.cpp BinaryNode.h

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h

BSTPathTest.o: BSTPathTest.cpp

.PHONY: clean
clean:
	-rm -f *.o a.out
