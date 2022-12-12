/* Morgan Kinne
   2150 Hash Lab 6 Pre-Lab */


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
//#include <unordered_set>
#include <stdlib.h>
#include "hashTable.h"
#include "timer.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

bool readInGrid (string filename, int &rows, int &cols);
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);

hashTable* htable;

int main(int argc, char* argv[]){
    int count = 0; // the current position in the input data
    int rows;
    int cols;
    string output;
    string outp_t;
    /*if(argc!=3){
            cout << "There was an error! Sorry to say but your code doesn't work nor can it be graded & your gonna fail! ~love gradescope";
        }
    else{ */
    int sizeOfDictionary = 0;
    string line;
    string dict = argv[1];
    bool isStored = readInGrid(argv[2], rows, cols);
    if(!isStored){
        cout << "Cannot read in grid!";
        exit(-1);
    }
    ifstream dFile(dict.c_str());
    if(dFile.is_open()){
        while(getline(dFile, line)){
            sizeOfDictionary++;
        }
        dFile.close();
    }
    htable = new hashTable(sizeOfDictionary);
    ifstream ndFile (dict.c_str());
    if(ndFile.is_open()){
        while(getline(ndFile, line)){
            htable->insert(line);
        }
        ndFile.close();
    }
    else{
        cout << "There was an error! No file was found";
    }
    //timer t;
    //t.start();
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            for(int dir = 0; dir<8; dir++){
                //bool isPrinted = true;
                for(int len = 3; len <= 22; len++){ //words in dictionary are 3 to 22 letters long
                   string findMe = getWordInGrid(r, c, dir, len, rows, cols);
                   if(findMe.length() == len){
                       if(htable->find(findMe)) {
                           if(dir == 0){
                               stringstream output;
                               output << "N (" << r << ", " << c << "):       " << findMe << endl;
                               outp_t += output.str();
                               count++;
                           }
                           if(dir == 1){
                               stringstream output;
                               output << "NE(" << r << ", " << c << "):       " << findMe << endl;
                               outp_t += output.str();
                               count++;
                           }
                           if(dir == 2){
                               stringstream output;
                               output << "E (" << r << ", " << c << "):       " << findMe << endl;
                               outp_t += output.str();
                               count++;
                           }
                           if(dir == 3){
                               stringstream output;
                               output << "SE(" << r << ", " << c << "):       " << findMe << endl;
                               outp_t += output.str();
                               count++;
                           }
                           if(dir == 4){
                               stringstream output;
                               output << "S (" << r << ", " << c << "):       " << findMe << endl;
                               outp_t += output.str();
                               count++;
                           }
                           if(dir == 5){
                               stringstream output;
                               output << "SW(" << r << ", " << c << "):       " << findMe << endl;
                               outp_t += output.str();
                               count++;
                           }
                           if(dir == 6){
                               stringstream output;
                               output << "W (" << r << ", " << c << "):       " << findMe << endl;
                               outp_t += output.str();
                               count++;
                           }
                           if(dir == 7){
                               stringstream output;
                               output << "NW(" << r << ", " << c << "):       " << findMe << endl;
                               outp_t += output.str();
                               count++;
                           }
                        }
                    }
                }
            }
        }
    }
    //t.stop();
    cout << outp_t;
    cout << count << " words found" << endl;
    //cout << "Found all words in " << t.getTime() << " seconds" << endl;
    return 0;
}

bool readInGrid (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // grid[][] array.  In the process, we'll print the grid to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
            //cout << grid[r][c];
        }
        //cout << endl;
    }
    // return success!
    return true;
}

char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocataion.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the grid
        output[pos++] = grid[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}
