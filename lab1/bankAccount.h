#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
using namespace std;

class bankAccount{
 public:
  bankAccount(); //default constructor
  bankAccount(double amount); //constructor if bank account is called w initial balance
  ~bankAccount(); //destructor, must be in h & cpp (nontest file)
  double withdraw(double amount); // method for withdrawing money returns new amount after withdrawal, if amount>balance returns og balance
  double deposit(double amount); // method for depositing money, returns new amount
  double getBalance(); //method that returns amount in acc(can be used in withdraw and deposit)
  
 private:
  double balance; // private variable w amount of money in account
};

#endif

  
  
