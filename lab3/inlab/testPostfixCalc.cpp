/* Author: Morgan Kinne
   Pre-Lab 3
   02/08 */

#include "postfixCalculator.h"
#include <iostream>
#include <stack>
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
