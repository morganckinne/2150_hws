// mathfun.cpp

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" long product (long, long);
extern "C" long power (long, long);

int  main () {
    //variables
    long x, y;
    
    cout << "Enter integer 1: ";
    cin >> x;
    cout << "Enter integer 2: ";
    cin >> y;
    cout << "Product: " << product(x,y) << endl; //return product of x and y
    cout << "Power: " << power(x,y) << endl; //return power of x^y
    
    return 0;
}
