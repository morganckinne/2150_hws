//heapnode.h
/*  Morgan Kinne
    CS 2150
    Prelab 10
 */

#ifndef HEAPNODE_H
#define HEAPNODE_H

#include <iostream>
using namespace std;

class heapnode{
    public:
        heapnode(); // constructor
        heapnode(int freq, char c); // constructor
        ~heapnode(); // destructor
        int getFreq();
        char getChar();
        heapnode*& getLeft();
        heapnode*& getRight();
        heapnode *left;
        heapnode *right;
        int frequency;
        char value;
};


#endif
