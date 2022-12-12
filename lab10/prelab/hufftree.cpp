/*  hufftree.cpp
    Reused code from inlab 5 (binary search tree)
 */
#include "hufftree.h"
#include "heapnode.h"
#include <iostream>
#include <string>
using namespace std;

hufftree::hufftree() {
    root = NULL;
}

hufftree::~hufftree() {
    delete root;
    root = NULL;
}


// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string hufftree::pathTo(const char& x) const {
    if(!find(x)){
        return "";
    }
    else{
        return pathTo(root, x);
    }
}

string hufftree::pathTo(heapnode* node, const char& x) const{
    if(x==node->value){
        return "";
    }
    else if(node->value == NULL){
        if(find(node->left, x)){
            return "0" + pathTo(node->left, x);
        }
        else if(find(node->right, x)){
            return "1" + pathTo(node->right, x);
        }
    }
    else if(x<node->value){
        return "0" + pathTo(node->left, x);
    }
    else if(x>node->value){
        return "1" + pathTo(node->right, x);
    }
    return "";
}

// find determines whether or not x exists in the tree.
bool hufftree::find(const char& x) const {
    if (root == NULL){
        cout <<"root";
    }
    return find(root, x);
}

//helper find method
bool hufftree::find(heapnode* node, const char& x) const {
    if(node == NULL){
        return false;
    }
    if(node->value == NULL){
        if(find(node->left, x)){
            return true;
        }
        if(find(node->right, x)){
            return true;
        }
    }
    if(x == node->value){
        return true;
    }
    else{
        if(x < node->value){
            return find(node->left, x);
        }
        if(x > node->value){
            return find(node->right, x);
        }
    }
    return false;
}
