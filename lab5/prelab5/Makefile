# This is a comment
#Morgan Kinne lab section 104

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

a.out: TreeCalc.o TreeCalcTest.o TreeNode.o
	$(CXX) $(DEBUG)  TreeCalc.o TreeCalcTest.o TreeNode.o -o a.out
	@echo "Pizza is Hot and Ready!"

TreeCalcTest.o: TreeCalcTest.cpp

TreeCalc.o: TreeCalc.cpp TreeCalc.h

TreeNode.o: TreeNode.cpp TreeNode.h

.PHONY: clean 
clean:
	-rm -f *.o a.out
