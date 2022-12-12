/* Morgan, Representation in Memory section of inlab
   02/08 */

#include <iostream>
#include <limits>
using namespace std;

bool isBool = true;
char isChar = '1';
int isInt = 1;
double isDouble = 1.0;
int* isIntPointer = &isInt;
/*

int intArray[10] = {0,1,2,3,4,5,6,7,8,9};

char charArray[10] = {'0','1','2','3','4','5','6','7','8','9'};

int intArray2D[6][5] = {{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};

char charArray2D[6][5] = {{'a','b','c','d','e'},{'a','b','c','d','e'},{'a','b','c','d','e'},{'a','b','c','d','e'},{'a','b','c','d','e'},{'a','b','c','d','e'}};
*/


int main(){
  double here = 1.0;
  cout << isBool << endl;
  cout << isChar << endl;
  cout << isInt << endl;
  cout << isDouble << endl;
  cout << isIntPointer << endl;
  cout << double_max<< endl;
}
