/* Author: Morgan Kinne
   Pre-Lab 3
   9/13 */

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
    else if(token == "-"){
      calc.subtract();
    }
    else{
      int x = stoi(token);
      calc.insert(x);
    }
  }
    calc.print(); 
  return 0;
}
