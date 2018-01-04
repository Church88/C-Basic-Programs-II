#include <iostream>
#include <cstdlib>
using namespace std;

void die(){ //If something goes wrong just exit.
	exit(EXIT_FAILURE);
}
void ConvertToMetric(float input){ //Takes a float and returns nothing, in this case just displaying text and computed conversions.
    int inches = 0; 
    int feet = 0;
    input *= 39.3700787; //Convert to inches
    input += .5; //Round
    feet = input/12; //Truncates to an int
    inches = (input - (feet*12)); //
    cout << feet << "ft " << inches << "in\n";
}
//Function takes no parameters and returns a float which is obtained from user input.
float FeetInput(){
    float ret;
    cin >> ret;
    if(!cin){
        die(); //Avoid issues with user input. Users cannot be trusted.    
    } 
    if(ret == 0){
        exit(EXIT_SUCCESS); //Quit out, with a successful completion.
    }
    if(ret < 0) { //Handle negatives.
        cout << "Error, only positive numbers are valid\n";
        die();
    }
    return ret; //Send back a good input.
}
int main(){
    cout << "Welcome to the meters to feet converter please enter the number of feet you would like to convert (decimal values are acceptable).\n" 
    << "Enter 0 to quit\n"; //User prompt.
    //Using camel case now, everything here is going to be run through functions.
    while(true){
        ConvertToMetric(FeetInput()); //The input function is providing the input for the conversion function.
    }
    return 0; //Oorah
}