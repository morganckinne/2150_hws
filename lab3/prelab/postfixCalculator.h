/* Morgan Kinne, 2150 Pre-Lab 3, 9/13 */
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <stack>
using namespace std;

class calculator {
 public:
  calculator();                // constructor    
  ~calculator();               // destructor
  void add();
  void subtract();
  void print();
  void insert(int n);

 private:
  stack<int> stackNum;
};

#endif

//create print method
//create ifEmpty method
