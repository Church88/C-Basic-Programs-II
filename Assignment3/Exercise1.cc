/*
TEST CASES
    Negative check
Case 1: -4
    Minumum check
Case 2: 1
    Smallest prime check
Case 3: 2
    Check a large even value
Case 4: 88
    Check bad input
Case 5: /.,
    Check a larger square value
Case 6: 169
    Basic checks on larger values
Case 7: 4861
Case 8: 7789
*/
#include <iostream>
#include <string>
#include <sstream> //For using string streams
#include <cmath> 
using namespace std;
/**
Checks the primality of a value
@param input is the incoming value to be tested
@return boolean value true means value is prime, false value is not prime
*/
bool PrimeTest(int input){
    if(input == 2){ //Handle the only even prime.
        return true;
    }
    if(input%2 == 0 || input < 2){//IF the input is not even or is greater than 2 we continue otherwise it is not a prime.
        return false;
    }
	int end = sqrt(input); //Capture the square root because this is largest possible multiplicative value that we need to check.
	for(int i = 3; i <= end; i+=2){//Loop is running on only odd values from 3 to square root of the number.
		if(input % i == 0){ //If the number is divisible by any smaller odd value up to and including the square root.
		    return false;
		}
	}
	return true;
}

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
    int user_input = 0;
    string check_string;
    while(true){
        cout << "Please enter a single positive integer to test for primality (type 'quit' to exit): ";
        getline(cin,check_string); //Take the entire line of input;
        if(check_string == "quit"){//The escape method.
            break;
        }
        if(!IsInt(check_string)){//If input is not an integer, prompt the user with an error message and loop back to the original prompt.
            cout << "Error bad input, try again.\n";
            continue;
        }
        user_input = StringToInt(check_string); //Send off the string to be converted to an integer.
        if(user_input == 42){
            cout << "42 is the correct answer however...\n"; //Fun is not a requirement but it enhances the user experience
        }
        if(PrimeTest(user_input)){ //Pass the number to PrimeTest and print a confirmation.
            cout << "Number is prime\n";    
        }  
        else {
            cout << "Number is not prime\n";
        }
    }
    return 0;
}