//Class implementation and IsPrime
#include <iostream>
#include <cmath>
#include <vector>
#include "Number.h"
using namespace std;
/**
* Member function that is invoked by an instance of the class.
* @return a bool if true then Number is prime.
*/
bool Number::isPrime(){
    int number = this->number;
    if(number == 2){ //Handle the only even prime.
        return true;
    }
    if(number%2 == 0 || number < 2){//If the Number is not even or is greater than 2 we continue otherwise it is not a prime.
        return false;
    }
	int end = sqrt(number); //Capture the square root because this is largest possible multiplicative value that we need to check.
	for(int i = 3; i <= end; i+=2){//Loop is running on only odd values from 3 to square root of the number.
	    if(number % i == 0){ //If the number is divisible by any smaller odd value up to and including the square root.
		    return false;
	    }
	}
	return true;
}
/**
 * Test the Number if it is divisible by the input parameter
 * @param int divisor is the value to be tested against the Number
 * @return bool if Number is divible by the parameter then true
*/
bool Number::isDivisibleBy(int divisor){
    int number = this->number;
    if(number%divisor == 0){
        return true;
    }
    return false;
}
/**
Takes in an integer and prints all prime numbers up to that value. Negative and minimum prime values are checked for
@param input the integer representing the maximum value
*/
void Number::printPrimesToNumber(){
    int input = this->number;
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