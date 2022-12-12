/* Morgan Kinne
   CS 2150 // Lab 2 // 9/6/2021 */

#include <iostream>
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"
using namespace std;

List::List(){
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;
}

//copy constructor, contents are same as source
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
}

List::~List(){ //body is empty from makeEmpty, so i call delete head and tail
  //delete all the elements we inserted (hint: do we already have a method for that?)
  //what else do we dynamically allocate that we need to delete?
  makeEmpty();
  delete head;
  delete tail;
  count=0;
}

//copy assignment operator, copy contents of every ListNode in source into existing list
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

// Returns true if empty, else false
bool List::isEmpty()const{
  if(count == 0){
    return true;
  }
  else{
    return false;
  }
}

//deletes all items except the dummy head/tail, list should be a working empty list after
void List::makeEmpty(){
  //make sure head and tail point to each other again
  //remember to set each ListNode to NULL as soon as you delete it, it can no longer be pointed to
  ListItr iter = ListItr(head->next);
    while(!iter.isPastEnd()){
      iter.moveForward();
      delete iter.current->previous;
    }
  head->next=tail;
  tail->previous=head;
}

// Returns an iterator that points to the first ListNode **after** the dummy head node (even on an empty list!)
ListItr List::first(){
  //trying to return the iterator right next to the head node
  //create list object, ListItrName
  ListItr nextToHead = ListItr(head->next);
  return nextToHead;
}

// Returns an iterator that points to the last ListNode **before** the dummy tail node (even on an empty list!)
ListItr List::last(){
  ListItr nextToTail = ListItr(tail->previous);
  return nextToTail;
}

// Inserts x after current iterator position
void List::insertAfter(int x, ListItr position){
  //insert the new ListNode after or before that ListNode
  ListNode* nn = new ListNode();
  nn->value = x;
  nn->next = position.current->next;
  nn->previous = position.current;
  position.current->next->previous = nn;
  position.current->next = nn;
  count++;
}

// Inserts x before current iterator position
void List::insertBefore(int x, ListItr position){
  //insert the new ListNode after or before that ListNode
  ListNode * nn = new ListNode();
  nn->value = x;
  nn->next = position.current;
  nn->previous = position.current->previous;
  position.current->previous = nn;
  nn->previous->next = nn;
  count++;
}

// Inserts x at tail of list
void List::insertAtTail(int x){
  ListNode* newNode = new ListNode();
  newNode->value=x;
  newNode->previous=tail->previous;
  newNode->next=tail;
  tail->previous->next = newNode;
  tail->previous=newNode;
  count++;
}

// Returns an iterator that points to the first occurrence of x.
// When the parameter is not in the list, return a ListItr object that points to the dummy tail node.
// This makes sense because you can test the return from find() to see if isPastEnd() is true.
ListItr List::find(int x){
  ListItr iter = ListItr(head->next);
  while(!iter.isPastEnd()){
    if(iter.retrieve()==x){
      break;
    }
    else{
      iter.moveForward();
    }
  }
  return iter;
}

// Removes the first occurrence of x
void List::remove(int x){
  ListItr iter = ListItr(find(x));
  iter.current->previous->next=iter.current->next;
  iter.current->next->previous=iter.current->previous;
  iter.current->next=NULL;

  iter.current->previous=NULL;
  delete iter.current;
  count--;
}

//Returns the number of elements in the list
int List::size() const{
  return count;
}

// printList: non-member function prototype
// prints list forwards (head -> tail) when forward is true
// or backwards (tail -> head) when forward is false
// You **must** use your ListItr class to implement this function
void printList(List& source, bool forward){
  if(forward){
    ListItr iter(source.first());
        while (!iter.isPastEnd()) {
	  cout <<  iter.retrieve() << " ";
          iter.moveForward();
        }
	cout<< endl;
  }
  else{
    ListItr iter(source.last());
    while(!iter.isPastBeginning()){
      cout<< iter.retrieve() << " ";
      iter.moveBackward();
    }
    cout<< endl;
  }
}
