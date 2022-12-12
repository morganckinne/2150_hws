/*  Traveling.cpp
    Skeleton Code provided by Bloomfield/Floryan (? i think)
    Morgan Kinne
    CS 2150 Inlab 11
    11/30/21
 */

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth &me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

/**
@brief main method
 @author morgan kinne & skeleton code author
 @date 11/30/21
 takes in travelling salesman route and returns shortest itinerary and distance
 @param argc an int representing the number of input arguments
 @param argv a char pointer to the input arguments
 @return int 0 to confirm program is running properly
 */

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    //testing compute distance and print method
    string start = dests[0];
    dests.erase(dests.begin());
    sort(dests.begin(), dests.end());
    vector<string> newdests = dests;
    
    //computeDistance(me, start, dests);
    
    float min = computeDistance(me, start, newdests);
    while(next_permutation(newdests.begin(), newdests.end())){
        float newmin = computeDistance(me, start, newdests);
        if(min > newmin){
            min = newmin;
            dests = newdests;
        }
    }
    
    //output
    cout << "Minimum path has distance " << min << ": ";
    printRoute(start, dests);
    return 0;
}

/**
@brief compute distance method
calculates distance between cities in middle earth
@author morgan kinne & skeleton code author
@date 11/30/21
@param me middle earth object
@param start a string representing the first city
@param dests a vector of the cities on the itinerary
@return float of the distance between the cities
*/
// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth &me, const string& start, vector<string> dests) {
    float count = me.getDistance(start, dests[0]);
    for(int i = 0; i<dests.size()-1; i++){
        count += me.getDistance(dests[i], dests[i+1]);
    }
    count += me.getDistance(dests[dests.size()-1], start);
    //printRoute(start, dests);
    //cout << endl << count;
    return count;
}
/**
@brief print route method
@author morgan kinne & skeleton code author
@date 11/30/21
prints out the route being taken in the itinerary
@param start a string of the first city in the itinerary
@param dests an array of the cities in the itinerary
@return void (cout)
*/
// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    cout << start << " -> ";
    for(int i = 0; i< dests.size(); i++){
        cout << dests[i] << " -> ";
    }
    cout << start; //<< endl;
}
