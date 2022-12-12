/* Author: Morgan Kinne
   Pre-Lab 3
   9/13 */

#include <iostream>
#include "ListNode.h"
#include "myStack.h"
#include "ListItr.h"
#include "postfixCalculator.h"
using namespace std;
#include <string>

int main(){
  calculator calc;
  string token;
  
  while(cin>>token){
    if(token == "+"){
      calc.add();
    }
    else if(token.length() == 1 && token  == "-"){
      calc.subtract();
    }
    else if(token == "*"){
      calc.mult();
    }
    else if(token == "/"){
      calc.divide();
    }
    else if(token == "~"){
      calc.negate();
    }
    else{
      int x = stoi(token);
      calc.insert(x);
    }
  }
    calc.print(); 
  return 0;
}
