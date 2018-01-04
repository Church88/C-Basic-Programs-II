#include <iostream>
#include <cmath>
#include <cassert> //Testing
#include <sstream>
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
        if(check.at(i) == '.' || check.at(i) == '-'){//Check for negatives and floats
            cout << "Error no floating point numbers or negative values\n";
            return false;
        }
        if(!isdigit(check.at(i))){//Check each char to see if it is a digit
            return false; //isdigit checks a char and returns a bool
        }
    }
    return true; //Return true if the whole string is digits.
}
/**
Convert a string to an integer, because I cannot use stoi().
@param input the incoming string to be converted
@return the integer version of the string
*/
int StringToInt(string input){
    int ret = 0; //The value that will be returned
    istringstream conversion(input); //Set up a input string stream with the value of the input string.
    if(!(conversion >> ret)){ //This will read in the stream into ret and if it fails it will execute the next line.
        ret = 0; //If the conversion fails make sure it is set to zero.
    }
    return ret;//Send back the integer value.
}
/**
Checks incoming integer value for primality
@param n the incoming integer value from main to be checked
@return a boolean value true if member is prime
*/
bool is_prime(int n){ //is_prime is a convention for variable naming but this is the given prompt
    if(n == 2){ //Check for the only even prime
        return true;
    }
    if(n < 2 || n%2 == 0){//Handle negatives, lowest prime, and evens
        return false;
    }
    int end = sqrt(n); //Capture the largest possible value to check for
    for(int i = 3; i <= end; i+=2){//Loop starts with the next lowest prime value to check and interates through odd values only
        if(n%i==0){
            return false; //If the value n is divisible by any value the loop iterates over
        }
    }
    return true; //Return true otherwise
}

int main () {
    //Do everything here
    cout << "Enter a positvie whole number greater than 2 for a print out of all prime values up to the number entered." <<
    " Type 'quit' to exit.\n";
    string input;
    int user_int = 0;
    while(true){
        getline(cin, input);
        if(input == "quit"){ //Check for sentinel value
            break;
        }
        if(!IsInt(input)){ //Send off the user input as a string to check if it is an integer
            cout << "Try again.\n";
            continue;
        }
        user_int = StringToInt(input); //Set the user_int to the integer value the user typed in after it has been checked
        if(user_int <= 2){ //No prime values less than 2
            cout << "Error please enter a value greater than 2.\n";
            continue;
        }
        cout << "All prime values up to " << user_int << endl;
        cout << 2 << endl; //First prime
        for(int i = 3; i <= user_int; i+=2){//Check all odd values up to the desired limit
            if(is_prime(i)){
                cout << i << endl;
            }
        }
        break;
    }   
    return 0;
}