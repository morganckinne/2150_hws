/*
 heap.h
 Morgan Kinne (11/22/21)
 CS 2150 Prelab 10
 Code Citation: Code written by Aaron Bloomfield, 2014
                Released under a CC BY-SA license
                This code is part of the https://github.com/aaronbloomfield/pdr repository
 */

#ifndef HEAP_H
#define HEAP_H

#include <vector>
//#include <unordered_map>
#include "heapnode.h"
using namespace std;

class heap {
public:
    heap();
    heap(vector<heapnode*> vec);
    ~heap();
    
    //void insert(int x, char y)
    void insert(heapnode* x);
    heapnode* findMin();
    heapnode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();
    //unordered_map<char, int>;
private:
    vector<heapnode*> heapN;
    unsigned int heap_size;
    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
