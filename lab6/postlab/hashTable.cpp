/* Morgan Kinne (mck7py)
   2150 - Hash (Pre-lab6)
    Hash Function takes inspiration from GeeksForGeeks C++ "https://www.geeksforgeeks.org/c-program-hashing-chaining/" page lines 48-57
    fmod function and define mod 1000000007 on line 14 & line 56 were found on "https://www.geeksforgeeks.org/modulo-1097-1000000007/"
    iterator function in bool find inspired by https://en.cppreference.com/w/cpp/iterator/iterator & https://thispointer.com/c-different-ways-to-iterate-over-a-list-of-objects/ on line 83
 */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include "hashTable.h"

using namespace std;
#define MOD 1000000007

hashTable::hashTable(){
    //size = 0;
    //table[size];
}

hashTable::hashTable(int dictSize) { //help
    //max = 0;
    table.resize(getNextPrime(dictSize));
    for(int i = 0; i < dictSize; i++){
        table[i] = NULL;
    }
}

/*hashTable::~hashTable{ //destructor, DO NOT USE
}*/

//need a find method, returns bool
bool hashTable::find(string word) {
    int wtf = hashFunc(word);
    if(table[wtf] == NULL){
         return false;
    }
    for(list<string>::iterator i=table[wtf]->begin(); i!=table[wtf]->end(); i++){
        if(word == *i) {
            return true;
        }
    }
    return false;
}
    
//need an insert method, returns void
void hashTable::insert(string word) {
    if(word.length() > size){
        size = word.length();
    }
    int key = hashFunc(word);
    if (table[key] == NULL) {
        table[key] = new list<string>;
    }
    table[key]->push_back(word);
}

//need a hash function, returns int
int hashTable::hashFunc(string word){
    unsigned int sum = 0;
    for(int i = 0; i<word.length(); i++){
        //sum+=word[i]*pow(37, i);
        sum = (sum*37) + word[i];
    }
    return sum%(table.size());
    //return fmod(sum, table.size());
}

//code given in prime_numbers.cpp
bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}
