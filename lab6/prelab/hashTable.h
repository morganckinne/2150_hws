/* Morgan Kinne (mck7py)
   2150 - Hash (Pre-lab 6) */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class hashTable {
    public:
        hashTable(); // constructor
        hashTable(int dictSize); //constructor that takes in size of dictionary
        //~hashTable();
        int hashFunc(string word);
        void insert(string word);
        bool find(string word);
        //int getSize();
        int size;
    private:
        //string table[1]
        vector<list<string>*> table;
};

//helper methods from prime_numbers.cpp
bool checkprime(unsigned int p); //checks if value is prime
int getNextPrime (unsigned int n); //returns next available prime value

#endif
