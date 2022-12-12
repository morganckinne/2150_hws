/*  huffmandec.cpp
    Morgan Kinne
    CS 2150
    Inlab 10
    11/23/21
    Citation: inlab-skeleton.cpp, given to us in lab document
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <unordered_map>
//#include "hufftree.h"
//#include "heapnode.h"
//#include "heap.h"
using namespace std;

int main(int argc, char* argv[]){
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    unordered_map<string, string> decode;
    unordered_map<string, string> encode;
    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code to a hashmap
        file >> prefix;
        decode[character] = prefix;
        //cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
    }

    // read in the second section of the file: the encoded message
    stringstream sstm;
    string decoded = "";
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
        unordered_map<string, string>::iterator p;
        for(p = decode.begin(); p != decode.end(); p++){
            /*
            string times = p->second;
            int time_s = 1;
            for(int i = 0; i<times.length(); i++){
                decoded += p->first;
            }
            //decoded += p->first;
             */
            if(bits == p->second){
                decoded += p->first;
            }
            //cout << p->first << " " << p->second << endl;
        }
    }

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();
    cout << decoded << endl;

    return 0;
}


