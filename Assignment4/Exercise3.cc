#include <iostream>
#include <cstdlib>
using namespace std;
char color_values[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}; //Global array of hex characters

/**
Generates a random string of six hexidecimal characters
@return a random hexidecimal string
*/
string SelectHexChar(){
    string ret;
    for(int j = 0; j < 6; j++){ //Inner loop runs 6 times
    //rand()% a number generates a value from 0 to the number -1!!!!!
            ret += (color_values[rand()%16]); //Print a random character from the array
        }
    return ret;
}

/**
Prints out a list of 100 random color values
*/
void PrintColors(){
    for(int i = 0; i < 100; i++){ //Outer loop runs 100 times
        cout << SelectHexChar() << endl; //
    }
}


int main(){
    srand(time(NULL)); //Seed number generator with the time since the epoch.
    PrintColors(); //Call our print function to do the work
    return 0; //Mic drop...
}