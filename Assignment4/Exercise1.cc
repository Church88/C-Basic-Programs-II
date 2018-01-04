#include <iostream>
#include <cmath>
#include <cassert> //Testing
using namespace std;

/**
Checks incoming integer value for primality
@param n the incoming integer value from main to be checked
@return a boolean value true if number is prime
*/
bool is_prime(int n){ //is_prime is a convention for variable naming but this is the given prompt
    assert(n>1); //Abort program if input is less than one. This circumvents the actual functionality rather than testing functionality.
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

int main(){
    assert(!is_prime(100));
    assert(is_prime(13.42)); //Function cannot on its own handle a float because the parameter is an int
    assert(!is_prime(169));
    //assert(!is_prime(0)); //This will not work either due to the assert statement inside the function.
    assert(is_prime(13));
    assert(is_prime(167));
    assert(is_prime(2617));
    assert(is_prime(2));
    //assert(!is_prime(-2)); //This will fail the program due to the assert statement inside the function.
    return 0;
}