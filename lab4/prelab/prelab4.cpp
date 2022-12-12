/* Author: Morgan Kinne
   2150 Pre-Lab 4
   02/08 */
#include <iostream>
#include <string>
using namespace std;

void sizeOfTest(){
   cout << "Size of int: " << sizeof(int) << endl;
   cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
   cout << "Size of float: " << sizeof(float) << endl;
   cout << "Size of double: " << sizeof(double) << endl;
   cout << "Size of char: " << sizeof(char) << endl;
   cout << "Size of bool: " << sizeof(bool) << endl;
   cout << "Size of int*: " << sizeof(int*) << endl;
   cout << "Size of char*: " << sizeof(char*) << endl;
   cout << "Size of double*: " << sizeof(double*) << endl;
}

void overflow(){
  unsigned int max = 4294967295;
  cout << max << " + 1 = " << max+1 << endl;
}

void outputBinary(unsigned int x){
  string binary = "";
  for (int i = 31; i >= 0; i--) {
    int k = x >> i;
    if (k & 1)
      binary+="1";
    else
      binary+="0";
    }

  string binary1 = binary.substr(0,4) + " ";
  string binary2 = binary.substr(4,4) + " ";
  string binary3 = binary.substr(8,4) + " ";
  string binary4 = binary.substr(12,4) + " ";
  string binary5 = binary.substr(16,4) + " ";
  string binary6 = binary.substr(20,4) + " ";
  string binary7 = binary.substr(24,4) + " ";
  string binary8 = binary.substr(28,4);

  string binaryi = binary1+binary2+binary3+binary4+binary5+binary6+binary7+binary8;

  cout<< binaryi<< endl;
}



int main(){
  sizeOfTest();
  overflow();
  unsigned int num = 0;
  cin>>num;
  outputBinary(num);
  return 0;
}
