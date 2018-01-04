#include <iostream>
#include <cstdlib>
using namespace std;


char color_values[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}; //Global array of hex characters
/**
Prints out a list of 100 random color values
*/
void PrintColors(){
    for(int i = 0; i < 100; i++){ //Outer loop runs 100 times
        for(int j = 0; j < 6; j++){ //Inner loop runs 6 times
        //MAKE SURE THAT IT IS RUNNING THE RIGHT RANGE!!!
            cout << (color_values[rand()%16]); //Print a random character from the array
        }
        cout << endl; //A new line after each 6 character color is printed
    }
}

int main(){
    srand(time(NULL)); //Seed number generator with the time since the epoch.
    PrintColors(); //Call our print function to do the work
    return 0; //Mic drop...
}