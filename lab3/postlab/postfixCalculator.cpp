/* Morgan Kinne
   2150 (Post-Lab 3)
   9/13
*/

//This is the postfix calculator that works with my own stack class

#include "postfixCalculator.h"
//#include "ListNode.h"
//#include "ListItr.h"
#include "myStack.h"
#include <iostream>
using namespace std;

calculator::calculator(){
}

calculator::~calculator(){
}

void calculator::add(){
  if(!stackNum.empty()){
    int x = stackNum.top();
    stackNum.pop();
    int y = stackNum.top();
    stackNum.pop();
    stackNum.push(y+x);
  }
}

void calculator::subtract(){
  if(!stackNum.empty()){
    int x = stackNum.top();
    stackNum.pop();
    int y = stackNum.top();
    stackNum.pop();
    stackNum.push(y-x);
  }
}

void calculator::mult(){
  if(!stackNum.empty()){
    int x = stackNum.top();
    stackNum.pop();
    int y = stackNum.top();
    stackNum.pop();
    stackNum.push(y*x);
  }
}


void calculator::divide(){
  if(!stackNum.empty()){
    int x = stackNum.top();
    stackNum.pop();
    int y = stackNum.top();
    stackNum.pop();
    stackNum.push(y/x);
  }
}


void calculator::negate(){
  if(!stackNum.empty()){
    int x = stackNum.top();
    stackNum.pop();
    stackNum.push(-(x));
  }
}

void calculator::print(){
  int x = stackNum.top();
  cout << x << endl;
}

void calculator::insert(int n){
  stackNum.push(n);
}
