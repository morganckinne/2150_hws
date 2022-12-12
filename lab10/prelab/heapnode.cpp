//heapnode.cpp
/*  Morgan Kinne
    Prelab 10
    CS 2150
 */

#include "heapnode.h"
#include <iostream>
using namespace std;

    heapnode::heapnode(){
        left = NULL;
        right = NULL;
    }
    heapnode::heapnode(int freq, char c){
        frequency = freq;
        value = c;
        left = NULL;
        right = NULL;
    }
    heapnode::~heapnode(){
        //empty destructor for now
    }
    int heapnode::getFreq(){
        return frequency;
    }
    char heapnode::getChar(){
        return value;
    }
    heapnode*& heapnode::getLeft(){
        return left;
    }
    heapnode*& heapnode::getRight(){
        return right;
    }

