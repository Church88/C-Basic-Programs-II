#include <iostream>
#include <cassert>
#include <sstream>
#include "Number.h"
using namespace std;

/**
Checks to make sure the input is entirely an integer
Also discards negatives and floats due to the '-' and '.'
@param check is the string value that is to be checked
@return is a boolean true indivates it is an integer
*/ 
bool IsInt(string check){
    if(check == ""){//In case an empty string is passed
        return false; 
    }
    for(int i = 0; i < check.size(); i++){ //For loop to iterate over the incoming string.
        if(!isdigit(check.at(i))){//Check each char to see if it is a digit
            return false; //isdigit checks a char and returns a bool
        }
    }
    return true; //Return true if the whole string is digits.
}

/**
Convert a string to a number, because I cannot use stoi().
@param input the incoming string to be converted
@return the integer version of the input
*/
int StringToInt(string input){
    int ret = 0; //The value that will be returned
    istringstream conversion(input); //Set up a input string stream with the value of the input string.
    if(!(conversion >> ret)){ //This will read in the stream into ret and if it fails it will execute the next line.
        ret = 0; //If the conversion fails make sure it is set to zero.
    }
    return ret;//Send back the value.
}

int main(){
    while(true){
        cout << "Enter a whole number greater than 2 for a print out of all primes up to the number entered: ";
        string input_string;
        getline(cin,input_string);
        int input_int = 0;
        if(IsInt(input_string)){ //Check user input to make sure it is an integer and positive
            input_int = StringToInt(input_string); 
        }
        else {
            cout << "Error try again\n";
            continue;
        }
        if(input_int < 2){ 
            cout << "Error number is less than 2\n";
            continue;
        }
        cout << "Valid input\n";
        Number user_number(input_int); //Make an instance of the Number class with the user input
        user_number.printPrimesToNumber(); //Print all primes
    }
    return 0;
}