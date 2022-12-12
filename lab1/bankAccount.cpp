#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include "bankAccount.h"
using namespace std;

bankAccount::bankAccount(){
  balance = 0;
}

bankAccount::bankAccount(double amount){
  balance  = amount;
}

bankAccount::~bankAccount(){
}

double bankAccount::withdraw(double amount){
  if(amount<balance){
    balance-=amount;
  }
  else{
  }
  return balance;
}

double bankAccount::deposit(double amount){
  balance+=amount;
  return balance;
}

double bankAccount::getBalance(){
  return balance;
}
  
  
