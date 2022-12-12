/*  Morgan Kinne (mck7py)
    01/23/2022
    xTon.cpp
*/

#include <iostream>
using namespace std;

int xton(int inp, int pow){
  if(pow == 0)
    return 1;
  else
    return inp*xton(inp, pow-1);
 }
int main(){
  int input, power;
  cin>> input;
  cin>> power;
  cout<<xton(input, power)<<endl;
  return 0;
}
