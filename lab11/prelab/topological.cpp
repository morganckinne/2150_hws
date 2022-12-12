/*
    topological.cpp
    Morgan Kinne
    CS 2150 (Prelab 11)
    11/28/21
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <queue>
using namespace std;

//helper methods
/**
 @brief topsort helper method
 @author Morgan Kinne
 @date 11/29/21
 sorts map topologically
 @param v map<string, vector<string>> &v (reference)
 @param c map<string, int> &c (reference)
 @return void, sorts referenced map v by comparing the indegree stored within map c
 */

/*  topsort algorithm: sort through each first index, and if you find it in any of the other p->second vectors, inc p and check that node, keep working until you find one that is not in any other vector
 
    what do I do if I find something that has no prereq (like 2 classes that are not connected to any of the other classes?
 */

void topsort(map<string, vector<string>> &v, map<string, int> &c){ //need to find item w indegree 0, and remove??
    map<string, vector<string> >::iterator x;
    map<string, int>::iterator y;
    queue<string> output;
    for(x = v.begin(); x != v.end(); x++){
        for(y = c.begin(); y!=c.end();y++){
            //cout << y->first <<" "<< y->second << "\n";
            
            
            
            
//            if(y->second == 0){ //(x->first == y->first) &&
//                //cout << "i'm reaching this part" << " " << x->first << endl;
//                output.push(y->first);
//                //cout << y->first << "\n";
//                y->second = -1;
//            }
            for(int i = 0; i<x->second.size(); i++){
                if(x->second[i] == y->first){
                    y->second--;
                    //cout << y->first << " " << y->second << "\n";
                }
            }
            if(y->second == 0){ //(x->first == y->first) &&
                //cout << "i'm reaching this part" << " " << x->first << endl;
                output.push(y->first);
                //cout << y->first << "\n";
                y->second = -1;
            }
        } //not reaching last index of counter y->first
    }
//    for(y = c.begin(); y!=c.end();y++){
//        for(x = v.begin(); x != v.end(); x++){
//            if(y->second == 0){ //(x->first == y->first) &&
//                //cout << "i'm reaching this part" << " " << x->first << endl;
//                output.push(y->first);
//                cout << y->first << "\n";
//                y->second = -1;
//            }
//            for(int i = 0; i<x->second.size(); i++){
//                if(x->second[i] == y->first){
//                    y->second--;
//                    cout << y->first << " " << y->second << "\n";
//                }
//            }
//        } //not reaching last index of counter y->first
//    }
    
    //output.push(c.rbegin()->first);
    //cout << c.rbegin()->first;
    while(!output.empty()){
        cout << output.front() << " ";
        output.pop();
    }
    cout << endl;
}

/**
 @brief printvec helper method
 @author Morgan Kinne
 @date 11/29/21
 prints unordered map
 @param v map<string, vector<string>> &v (reference)
 @return void (cout the string and vectors)
 */
void printvec(map<string, vector<string>> &v){
    map<string, vector<string> >::iterator x;
    vector<string>::iterator y;
    for (x = v.begin(); x != v.end(); x++) {
        cout << x->first << " : ";
        for(int i = 0; i<x->second.size(); i++){
            cout << x->second[i] << " ";
        }
        cout << endl;
    }
}


/**
 @brief printcount helper method
 @author Morgan Kinne
 @date 11/29/21
 prints unordered map
 @param c map<string, int> &c (reference)
 @return void (cout the string and ints)
 */
void printcount(map<string, int> &c){
    map<string, int>::iterator x;
    for (x = c.begin(); x != c.end(); x++) {
        cout << x->first << " : " << x->second << endl;
    }
}

/**
 @brief main method
 @author Morgan Kinne
 @date 11/29/21
 accomplishes purpose of inserting, sorting, and printing map with a topological sort
 @param argc an int counting the number of inputs
 @param argv[] a char pointer to the input values
 @return int 0, to make sure the program is running properly (cout topological sort)
 */

int main(int argc, char* argv[]){
    map<string, vector<string>> vec;
    
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    ifstream file(argv[1]);
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }
    map<string, int> counter;
    while(true){
        string s1, s2;
        file >> s1;
        file >> s2;
        if(s1 == "0" && s2 == "0"){
            break;
        }
        else{
            if(counter[s1] <-2){//.find(s1)!=counter.end()){
                counter[s1] = 0; //head values marked as 0
            }
            vec[s1].push_back(s2); //head, tail (regardless of if head repeats, only tail pushed on unless head is new)
            counter[s2]++; //tail values ONLY incremented
        }
    }
    //printcount(counter);
    topsort(vec, counter);
    //printvec(vec);
    //printcount(counter);
    return 0;
}
