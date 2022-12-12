#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    insert(root, x);
}

void AVLTree::insert(AVLNode*& node, const string& x){
    if(node==NULL){
        node = new AVLNode();
        node->value = x;
        node->left = NULL;
        node->right = NULL;
        node->height = 0;
    }
    else if(x<node->value){
        insert(node->left, x);
    }
    else if(x>node->value){
        insert(node->right, x);
    }
    else{
        ;
    }
    node->height = max(height(node->left), height(node->right)) + 1;
    balance(node);
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string x) const {
    if(!find(x)){
        return "";
    }
    else{
        return pathTo(root, x);
    }
}

string AVLTree::pathTo(AVLNode * const & node, const string x) const{
    if(x==node->value){
        return node->value;
    }
    else if(x<node->value){
        return node->value + " " + pathTo(node->left, x);
    }
    else if(x>node->value){
        return node->value + " " + pathTo(node->right, x);
    }
    return "";
}

//original method
bool AVLTree::find(const string& x) const {
    return find(root, x);
}

// find determines whether or not x exists in the tree.
//helper method
bool AVLTree::find(AVLNode* node, const string& x) const {
    if(node == NULL){
        return false;
    }
    else if(x == node->value){
        return true;
    }
    else{
        if(x < node->value){
            return find(node->left, x);
        }
        else if(x > node->value){
            return find(node->right, x);
        }
    }
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    return numNodes(root);
}

int AVLTree::numNodes(AVLNode * const & node) const{
    if(node==NULL){
        return 0;
    }
    else{
        return 1+numNodes(node->left)+numNodes(node->right);
    }
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& node) {
    //need to compare the values of the nodes, if the node->left->left->value is
    if(height(node->right)-height(node->left) == 2){
        if(height(node->right->right)-height(node->right->left) <= -1){
            node->right = rotateRight(node->right);
        }
        node = rotateLeft(node);
    }
    else if(height(node->right)-height(node->left) == -2){
        if(height(node->left->right)-height(node->left->left) >= 1){
            node->left = rotateLeft(node->left);
        }
        node = rotateRight(node);
    }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& node) {
    AVLNode* newNode = node->right; //initialize newNode
    node->right = newNode->left;
    newNode->left = node;
    node->height = max(height(node->left), height(node->right))+1;
    newNode->height  = max(height(newNode->left), node->height)+1;
    node = newNode; //replace old node
    return node;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& node) {
    AVLNode* newNode = node->left;
    node->left = newNode->right;
    newNode->right = node;
    node->height = max(height(node->right), height(node->left))+1;
    newNode->height  = max(height(newNode->right), node->height)+1;
    node = newNode;
    return node;
}
                    
//potentially make private helper method that allows double rotations in either direction?? or should I call then both in the same method in diff. orders?? confusion.s

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
