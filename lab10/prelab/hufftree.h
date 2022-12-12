/*  hufftree.h
    Reused code from inlab 5 (binary search tree)
 */

#ifndef HUFFTREE_H
#define HUFFTREE_H

#include "heapnode.h"
#include <iostream>
#include <string>
using namespace std;

class hufftree {
public:
    hufftree();
    ~hufftree();
    string pathTo(const char& x) const;
    bool find(const char& x) const;
    
    heapnode* root;
    
    private:
        //helper method
        string pathTo(heapnode* node, const char& x) const;
        bool find(heapnode* node, const char& x) const;
};

#endif
