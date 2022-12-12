//huffmanenc.cpp
/*  Morgan Kinne
    CS 2150
    Lab 10 Pre-lab
    huffmanenc.cpp
    Citation: fileio.cpp, given to us in lab document (lines 21 through 30 & 36)
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <unordered_map>
#include "hufftree.h"
#include "heapnode.h"
#include "heap.h"
using namespace std;

int main(int argc, char* argv[]){
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    ifstream file(argv[1]);
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }
    char g;
    unordered_map<char, int> fxc;
    //vector <int> freqVec();
    //vector <char> charVec();
    heap* h = new heap();
    //heapnode* og = new heapnode();
    int num = 0;
    while(file.get(g)) {
        if ((int) g < 32){}
        else if(fxc[g] == NULL){
            fxc[g] = 1;
            num++;
        }
        else{
            fxc[g]++;
            num++;
        }
    }
    unordered_map<char, int>::iterator p;
    for(p = fxc.begin(); p != fxc.end(); p++){
        heapnode* hn = new heapnode(p->second, p->first);
        h->insert(hn);
    }
    
    int d_sym = h->size();
    
    while(h->size() > 1){
        heapnode* og = h->deleteMin();
        heapnode* ob1 = h->deleteMin();
        heapnode* ob2 = new heapnode();
        ob2->right = og;
        ob2->left = ob1;
        int totalfreq = og->frequency + ob1->frequency;
        ob2->frequency = totalfreq;
        h->insert(ob2);
    }
    //cout << h->size();
    hufftree* ht = new hufftree();
    ht->root = h->findMin();
    /*cout<<ht->root->frequency;
    cout<<ht->root->left->frequency;
    cout<<ht->root->right->value;
    cout<<ht->root->right->frequency;*/
    
    
    for(p = fxc.begin(); p != fxc.end(); p++){
        //cout << p->first;
        string character(1, p->first);
        if (character == " "){
            character = "space";
        }
        
        //cout << p->second << endl;
        cout << character << "\t" << ht->pathTo(p->first) << "\t" << endl;
    }

    cout << "----------------------------------------" << endl;

    file.clear();
    file.seekg(0);
    
    int numEncoded = 0;
    while(file.get(g)){
        cout << ht->pathTo(g) << " ";
        numEncoded += (ht->pathTo(g)).size();
    }
    
    cout << endl;
    cout << "----------------------------------------" << endl;
    
    cout <<"There are a total of " << num << " symbols that are encoded." << endl;
    cout <<"There are " << d_sym << " distinct symbols used." << endl;
    cout <<"There were " << num*8 << " bits in the original file." << endl;
    cout <<"There were " << numEncoded << " bits in the compressed file." << endl;
    cout << setprecision(5)<<fixed;
    double compress = ((num*8.0/numEncoded) * 1.0);
    double cost = (numEncoded)*(1.0)/num;
    cout <<"This gives a compression ratio of " <<  compress << "." << endl;
    cout <<"The cost of the Huffman tree is " <<  cost << " bits per character." << endl;
    return 0;
}
/*
 for math above: num = num of symbols encoded
                freqVec.size()
 */
