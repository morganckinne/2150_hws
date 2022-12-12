/* Morgan Kinne
   CS 2150 // Lab 2 // 9/6/2021 */

#include <iostream>
#include "ListNode.h"
#include "ListItr.h"
//#include "myStack.h"

using namespace std;

ListItr::ListItr(){
  current = NULL;
}

ListItr::ListItr(ListNode* theNode){
  current = theNode;
}

// Returns true if the iterator is currently pointing past the end position
// in the list (i.e., it's pointing to the dummy tail), else false
bool ListItr::isPastEnd() const{
  //check to see if null value past tail
  if(current->next==NULL){
    return true;
  }
  else{
    return false;
  }
}

// Returns true if the iterator is currently pointing past (before) the first position
// in list (i.e., it's pointing to the dummy head), else fals
bool ListItr::isPastBeginning() const{
  if(current->previous==NULL){
    return true;
  }
  else{
    return false;
  }
}

// Advances `current` to the next position in the list (unless already past the end of the list
void ListItr::moveForward(){
  if(!isPastEnd()){
    ListNode tempNode = *current;
    current = tempNode.next;
  }
}

// Moves `current` back to the previous position in the list (unless already past the beginning of the list
void ListItr::moveBackward(){
  if(!isPastBeginning()){
    current=current->previous;
  }
}

// Returns the value of the item in the current position of the lis
int ListItr::retrieve() const{
  ListNode tempNode = *current;
  int temp = tempNode.value;
  return temp;
}
