/* Morgan Kinne
   2150 (Post-Lab 3)
   9/13 */
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "myStack.h"
//#include "ListItr.h"
//#include "ListNode.h"
using namespace std;

class calculator {
 public:
  calculator();                // constructor    
  ~calculator();               // destructor
  void add();
  void subtract();
  void mult();
  void divide();
  void negate();
  void print();
  void insert(int n);

 private:
  myStack stackNum;
};

#endif
