/*
 heap.cpp
 Morgan Kinne (11/22/21)
 CS 2150 Prelab 10
 Code Citation: Code written by Aaron Bloomfield, 2014
                Released under a CC BY-SA license
                This code is part of the https://github.com/aaronbloomfield/pdr repository
 */

#include <iostream>
//#include <unordered_map>
#include "heap.h"
#include "heapnode.h"
using namespace std;

// default constructor
heap::heap() : heap_size(0) {
    heapN.push_back(0);
}

// builds a heap from an unsorted vector
heap::heap(vector<heapnode*> vec) : heap_size(vec.size()) {
    heapN = vec;
    heapN.push_back(heapN[0]);
    //heapnode* node = new heapnode();
    heapN[0] = 0;
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
heap::~heap() {
}

/*void heap::insert(int x, char y) {
    heapnode* newhuff = new heapnode(x, y)
    // a vector push_back will resize as necessary
    heap.push_back(newhuff);
    // move it up into the right position
    percolateUp(++heap_size);
}*/

void heap::insert(heapnode* x){
    heapN.push_back(x);
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    heapnode* x = heapN[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x->frequency < heapN[hole/2]->frequency); hole /= 2) {
        heapN[hole] = heapN[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    heapN[hole] = x;
}

heapnode* heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    heapnode* ret = heapN[1];
    // move the last inserted position into the root
    heapN[1] = heapN[heap_size--];
    // make sure the vector knows that there is one less element
    heapN.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    heapnode* x = heapN[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (heapN[child+1]->frequency < heapN[child]->frequency)) {
            child++;
        }
        // if the child is greater than the node...
        if (x->frequency > heapN[child]->frequency) {
            heapN[hole] = heapN[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    heapN[hole] = x;
}

heapnode* heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return heapN[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    heapN.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(" << heapN[0] << ") ";
    for (int i = 1; i <= heap_size; i++) {
        cout << heapN[i]->frequency << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}
