/*
TEST CASES
    First prime check
Case 1: 2
    First square check
Case 2: 4
    Small value check
Case 3: 10
    Bad input no negatives
Case 4: -12
    Bad input no floats
Case 5: 1.456
    Break down a large square
Case 6: 1000
    Large square
Case 7: 169
    Large prime value
Case 8: 167
*/
#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
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
Takes a value and prints out all the prime factors of the value.
@param input is the value that the factors will be derived from
*/
void PrintPrimeFactors(int input){
    int copy_input = input; //Make a copy of input because we are going to modify the incoming value
    vector<int> factors; //Set up a vector to hold the factors to be printed out.
    int end = sqrt(input); //Capture the largest possible multiplicative value of the input
    for(int i = 2; i <= end; i++){
        if(input%i == 0){//If the value is divisible by i push back i because it is a factor
            factors.push_back(i);
            input/=i; //Set input to the remaining value after the found factor is taken out
            i--; //Decrement i to check if there are repeating factors
        }
    }
    if(input != 1){ //Check if the last factor is not 1
        factors.push_back(input); //Add the last factor to the vector if it is not 1.
    }
    cout << "Prime factors of " << copy_input << " are:\n"; //Print out copy of the original.
    for(int i = 0; i < factors.size(); i++){//Print out the factors.
        cout << factors.at(i) << endl;
    }
}
int main(){
    int user_input = 0;
    string check_string;
    while(true){
        cout << "Please enter a positive integer greater than 1 (type 'quit' to exit): ";
        getline(cin,check_string); //Take the entire line of input.
        if(check_string == "quit"){//Check for the sentinel value
            break;
        }
        if(!IsInt(check_string)){//If input is not an integer, prompt the user with an error message and loop back to the original prompt.
            cout << "Error bad input, try again.\n";
            continue;
        }
        user_input = StringToInt(check_string); //Send off the string to be converted to an integer.
        if(user_input <= 1){
            cout << "Error integer must be greater than 1.\n";
            continue;
        }
        PrintPrimeFactors(user_input); //Handle the printing and computation in the function.
    }
    return 0;
}