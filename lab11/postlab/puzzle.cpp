/*  postlab 11
    puzzle.cpp
    Morgan Kinne
    12/01/21
    swap idea from: https://stackoverflow.com/questions/956199/how-to-swap-string-characters-in-java
 */

#include <iostream>
#include <map>
#include <queue>
using namespace std;

//need to add doxyfile comments
/*
 should I break the string up into 3 parts, and have that attached to the full string in a vector, and then shuffle it around?? tbh very confused how to do this conceptually
 */

/**
 @brief swap method
 swaps two characters in a string
 @author Morgan Kinne & idea from https://stackoverflow.com/questions/956199/how-to-swap-string-characters-in-java
 @date 12/01/21
 @param puz a string representing the current letter organization
 @param place an int for the index
 @param otherplace an int for the other index to be swapped
 @return string with swapped characters
 */
string swap(string puz, int place, int otherplace){
    string newpuz = puz;
    char x = newpuz[place];
    newpuz[place] = newpuz[otherplace];
    newpuz[otherplace] = x;
    return newpuz;
}

/**
 @brief destination state method
 finds possible destinations of the string
 @author Morgan Kinne
 @date 12/01/21
 @param puzzle a string of the current puzzle organization
 @return vector with possible string combos
 */
vector<string> deststate(string puzzle){
    vector<string> puzzlevec;
    int x = puzzle.find("0");
    if(x >= 3){
       puzzlevec.push_back(swap(puzzle, x, x-3));
    }
    if(x <= 5){
        puzzlevec.push_back(swap(puzzle, x, x+3));
    }
    if(x%3 != 0){ //should this be an else if or an if
        puzzlevec.push_back(swap(puzzle, x, x-1));
    }
    if(x%3 != 2){
        puzzlevec.push_back(swap(puzzle, x, x+1));
    }
    //this is where i need to find the possible destination states of the puzzle
    return puzzlevec;
}

int main(int argc, char* argv[]){
    queue<string> grid;
    map<string, int> counter;
    string a, b, c, d, e, f, g, h, i;
    cout << "Enter puzzle" << endl;
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    cin >> g >> h >> i;
    string puzzle = a + b + c + d + e + f + g + h + i;
    //cout << puzzle;
    grid.push(puzzle);
    while(grid.size()>0){
        puzzle = grid.front();
        grid.pop();
        if(puzzle == "123456780"){ //need to have case where puzzle does not equal that bc it is unsolvable
            break;
        }
        else{
            vector<string> temp = deststate(puzzle);
            for(int i = 0; i<temp.size(); i++){
                if(counter.count(temp[i]) <= 0){
                //if(grid.front() != temp[i]){ //this line is the issue
                    grid.push(temp[i]);
                    counter[temp[i]] = 1 + counter[puzzle];
                }
            }
        }
    }
    //cout << puzzle << " " << counter[puzzle] << endl;
    if(puzzle != "123456780"){ //what are we supposed to return if the puzzle is unsolveable
        //cout << "IMPOSSIBLE"; //<< endl << counter[puzzle] << " " << puzzle;
        exit(1);
    }
    else{
        cout << counter[puzzle];
    }
    return 0;
}
