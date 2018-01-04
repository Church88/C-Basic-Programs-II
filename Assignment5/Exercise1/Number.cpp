//Class implementation and IsPrime
#include <iostream>
#include <cmath>
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
 * Member function to determine if the parameter is a divisor of the number.
 * @param int divisor is the value that the number will be divided by
 * return bool if Number is divisible by prarm then true
*/
bool Number::isDivisibleBy(int divisor){
    int number = this->number; //Make a copy of the number to do math on.
    if(number%divisor == 0){
        return true;
    }
    return false; //If not divisible then false
}