# This is a comment
#Morgan Kinne lab section ?

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

a.out: AVLNode.o AVLTree.o AVLPathTest.o
	$(CXX) $(DEBUG) AVLNode.o AVLTree.o AVLPathTest.o -o a.out
	@echo "Pizza is Hot and Ready!"

AVLNode.o: AVLNode.cpp AVLNode.h

AVLTree.o: AVLTree.cpp AVLTree.h

AVLPathTest.o: AVLPathTest.cpp

.PHONY: clean
clean:
	-rm -f *.o a.out
