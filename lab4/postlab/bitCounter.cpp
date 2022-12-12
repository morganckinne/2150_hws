/*  Morgan K
    Post-lab 4
    02/15 */
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
//#include <string>
using namespace std;

//recursive bit counting function
int recBitCount(int n){
  if(n==0){
    return 0;
  }
  else if(n%2==0){
    return recBitCount(n/2);
  }
  else if(n%2==1){
    return 1+recBitCount(n/2);
  }
}

int isNum(char x){
    if(x>='0' && x <= '9'){//if value is between 0 and 10, return int val
        return (int)x - '0';//convert to int
    }
    else{
        return (int)x - 'A' + 10;
    }
}

char isNumRev(int num){ //this is one issue, or is it?
    if(num >= 0 && num <= 9){
        //cout << "This is happening";
        return (char)(num + '0');
        //cout << (char)(num + '0');
    }
    else{
        cout << "This is happening: "; // << (num - 'A' + 10);
        //cout << num;
        return (char)num - 'A' + 10;
        //cout << (char)num - 'A' + 10;
    }
}

int toDec(string num, int base){ //(un?)successfully converts from startbasebase to decimal
    if(base == 10){
        //cout << "I'm reaching this point.";
        return stoi(num);
    }
    int pow = 1;
    int newNum = 0;
    for(int i = num.size() - 1; i>= 0; i --){
        newNum += isNum(num[i]) * pow;
        pow *= base;
        //cout << newNum;
    }
    //cout << "In dec form: " << newNum << "\n";
    return newNum;
}

string toBase(int num, int base){
    string newNum = "";
    while(num > 0){
        //cout << num << ", " << (num%base) << endl;
        newNum+=isNumRev(num%base);
        num/=base;
        //cout << newNum << " " << num;
    }
    reverse(newNum.begin(), newNum.end());
    return newNum;
}

  
string baseConvert(string num, int startbase, int endbase){
    //string alph = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if(startbase == endbase){ //return original input
        return num;
    }
    else if(startbase > 36 || endbase > 36 || startbase < 2 || endbase < 2){
      cout << "Invalid input." << endl;
        //base is greater than 36 or less than 2, return string saying invalid
    }
    else{
        int temp = toDec(num, startbase);
        //cout << temp << "to dec is happening";
        if(endbase == 10){ //converting from something to decimal
            //cout << temp;
            return to_string(temp);
        }
        else{
            //cout << toBase(temp, endbase);
            return toBase(temp, endbase); //from decimal to endbase
            //convert somehow from string to int
        }
    }
}

int main (int argc, char* argv[]){ // do recBitCount(argv)
  if(argc != 5){
    cout << "There was an error. Too many or too little inputs." << endl;
  }
  else{
    //set variable to argv[position]
    int arg1 = stoi(argv[1]);
    int arg3 = stoi(argv[3]);
    int arg4 = stoi(argv[4]);
    cout << arg1 << " has " << recBitCount(arg1) << " bit(s)" << endl;
    cout << argv[2] << "(base " << arg3 << ") = " << baseConvert(argv[2],arg3,arg4) << "(base " << arg4 << ")" << endl;
    return 0;
  }
}
