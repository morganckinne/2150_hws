/* Author: Morgan Kinne
   2150 (PostLab3)
   9/15
 */

#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include "ListItr.h"
#include "ListNode.h"
using namespace std;

class myStack {
public:
    myStack();//constructor

    ~myStack(); // destructor
    
    void makeEmpty();

    bool empty() const; //if stack is empty, return true

    void push(int x); // insert method at end of "stack"

    void pop(); //remove last method
    
    int top(); //returns tail->previous

private:
    ListNode* head;       // Dummy node representing the beginning of the list
    ListNode* tail;       // Dummy node representing the end of the list
    int count;            // Number of elements in the list
    
    friend class ListItr;
    
    //friend class ListNode;
};

#endif
