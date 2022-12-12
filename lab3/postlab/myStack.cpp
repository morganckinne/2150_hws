/* Author: Morgan Kinne
   CS 2150 (Post-Lab 3)
   9/15 */

#include <iostream>
#include "ListNode.h"
#include "myStack.h"
#include "ListItr.h" // include list itr h in other files
using namespace std;

myStack::myStack(){
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;
}

myStack::~myStack(){
  makeEmpty();
  delete head;
  delete tail;
  count=0;
}

void myStack::makeEmpty(){
  ListItr iter = ListItr(head->next);
    while(!iter.isPastEnd()){
      iter.moveForward();
      delete iter.current->previous;
    }
  head->next=tail;
  tail->previous=head;
}

// Returns true if empty, else false
bool myStack::empty()const{
  if(count == 0){
    return true;
  }
  else{
    return false;
  }
}

// Inserts x at tail of list
void myStack::push(int x){
  ListNode* newNode = new ListNode();
  newNode->value=x;
  newNode->previous=tail->previous;
  newNode->next=tail;
  tail->previous->next = newNode;
  tail->previous=newNode;
  count++;
}

// Removes the top value
void myStack::pop(){
  if(!empty()){
    ListItr iter = ListItr(tail->previous);
    iter.current->previous->next=iter.current->next;
    iter.current->next->previous=iter.current->previous;
    iter.current->next=NULL;
    iter.current->previous=NULL;
    delete iter.current;
    count--;
  }
}

int myStack::top(){ //retrieves the last element (tail->previous)
  return tail->previous->value;
}
