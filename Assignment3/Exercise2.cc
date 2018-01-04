/*
TEST CASES
    Negative values
Case 1: -10 
    Zero check
Case 2: 0 
    Basic check
Case 3: 1000
    Check up to a prime
Case 4: 5
    Check for bad input
Case 5: ./,
    Check for perfect square
Case 6: 169
    Check performance, it is quite slow with server lag
Case 7: 99999999
    Check for float, should fail
Case 8: 1456.98
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream> //For using string streams
#include <cmath> 
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
    return ret;//Send back the integer value.
}
/**
Takes in an integer and prints all prime numbers up to that value. Negative and minimum prime values are checked for
@param input the integer representing the maximum value
*/
void PrintPrimes(int input){
    if(input < 1){ //Handle the lowest value allowed
        cout << "No prime values less that one\n";
    }
    vector<bool> sieve ((input+1),true); //Create a vector of bools set to true that is one more than the user input
    //This is because we are using the value of the index as the output. User enters 9 we need a vector with a max index equal to 9 therefore a vector size 10.
    int end = sqrt(input); //Capture the max value that needs to be checked.
    for(int i = 2; i <= end; i++){ //Outer loop is running till the max possible value to check.
        if(sieve.at(i)){//For every true value on the vector
            for(int j = (i*i); j <= input; j+=i){//This is an implementation of the Sieve of Eratoshenes.
            //First it runs through all index positions that are a multiple of two, three and so on.
                sieve.at(j) = false;
                //Any index that is a multiple of a smaller prime is marked false.
            }
        }
    }
    //Print out any index values that are still true.
    for(int i = 2; i <= input; i++){
        if(sieve.at(i)){
            cout << i << endl;
        }
    }
}
int main(){
    int user_input = 0;
    string check_string;
    while(true){
        cout << "Please enter a single positive integer to list all prime values to that number (type 'quit' to exit): ";
        getline(cin,check_string); //Take the entire line of input
        if(check_string == "quit"){//Check for the sentinel value
            break;
        }
        if(!IsInt(check_string)){//If input is not an integer, prompt the user with an error message and loop back to the original prompt.
            cout << "Error bad input, try again.\n";
            continue;
        }
        user_input = StringToInt(check_string); //Send off the string to be converted to an integer.
        PrintPrimes(user_input); //Send the input to the PrimePrint function
    }
    return 0;
}