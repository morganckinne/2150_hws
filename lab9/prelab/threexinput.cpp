/* Morgan Kinne
   CS 2150
   Lab 9 Prelab
   11/11/2021
*/

#include <iostream>
#include <cstdlib>
#include "timer.h"
using namespace std;

extern "C" long threexplusone (long, long);
 
int main(){
    long x; //num
    long n; //numtimes
    timer t;
    
    //cout << "Enter a number: ";
    cin >> x;
    //cout << "Enter iterations of subroutine: ";
    cin >> n;
    
    long og = threexplusone(x, 1);
    t.start();
    long newOne = threexplusone(x, n);
    t.stop();
    //cout << t.getTime();
    cout << newOne;
    
/* psuedocode for assembly:
  if(x%2 == 0){
    x/=2;
  }
  else{
    x = 3x+1;
  }

  for(int i = 0; i<n; i++){
    count++;
     if(x%2 == 0){
       x/=2;
     }
     else{
       x = 3x+1;
     }
  } */
  return 0;
}
