/* Morgan Kinne
   CS 2150 // Lab 2 // 9/6/2021 */

#include <iostream>
#include "ListNode.h"
#include "ListItr.h"
#include "myStack.h"
//#include "List.h"
using namespace std;

ListNode::ListNode(){
  value = 0;
  next = NULL;      // ListNode* next
  previous = NULL;  //ListNode* previous
}
