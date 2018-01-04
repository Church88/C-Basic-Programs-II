#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
using namespace std;

void die(){ //If something goes wrong just exit signalling a failure has occured.
	exit(EXIT_FAILURE);
}
//Function that returns a vector of doubles and takes no parameters.
vector<double> input(){ //Function for handling user input returning a vector of doubles.
    //Now we do some work around becase C++98 will not do a simple vector initialization.
    char arr_xyz[] = {'x','y','z'};//Characters for the user to associate with inputs.
    vector<char> vec_xyz (arr_xyz,arr_xyz+sizeof(arr_xyz)/sizeof(char)); //And this is how a vector can be initialized to set values in C++98
    vector<double> ret_values (3,0.0); //Set up a vector for storing the inputs.
    double user_input = 0.0;
    int count = 0; //Used for keeping track of position
    while(true){ 
        cout << "Enter a value for " << vec_xyz.at(count) << ": "; //User prompt displaying the proper character to input.
        cin>>user_input;
        if(!cin){ //Users cannot be trusted so if anything but a number comes in program quits.
            cout << "Error with input.\n"; //Not a fully fleshed out input handler but it will kill some bugs.
            die();
        }
        ret_values.at(count) = user_input; //Inputs are stored in a vector.
        if(count == ret_values.size()-1){ //Checks to see if the count has reached the last position on the vector.
            break; //Once vector is full break out.
        }
        count++; //Iterate across vector by one each time.
    }
    return ret_values; //Send the input values back in the vector.
}
//Function returns a double, taking two double parameters and returning their sum.
double sum(double x, double y, double z){ //Add and return.
    return x+y+z;
}
//Function returns a double, taking one double as a parameter and returning the sine of that double.
double sine(double x) { //Probably too elaborate but leaves room for expansion.
    return sin(x);
}
//Function takes three doubles and returns a double.
double cosine_plus_some(double x, double y, double z){ 
    if(z==0){ //Handling the divide by zero issue
        cout << "Unable to compute due to divide by zero.";
        return 0.0;
    }
    return cos((x+y)/z); //Computed double to be returned.
}
//Function takes three doubles and returns the average as a doulbe.
double average(double x, double y, double z){ //Nothing fancy just a simple average.
    return (x+y+z)/3;
}
//Function takes a double and retunrs the log base 2 of that double as a double.
double log_base_2(double x){//Fancy built-in log base 2, did not know it existed. Otherwise log(x)/log(anybase) will get it done.
    return log2(x);
}
int main(){ 
    cout << "Input will consist of 3 floating point values:\n";
    vector<double> values = input(); //Set up a vector that recieves its values from the input function.
    double x = values.at(0); //Grab the values from the vector so the function calls do not involve acessing as well.
    double y = values.at(1); //Plenty of more efficient ways to do this but for three terms no real impact, this would be better suited for handling larger inputs.
    double z = values.at(2);
    cout << "This is the sum: " << sum(x,y,z) << endl; //Spits out all of the return values with some clarification.
    cout << "The sine of x: " << sine(x) << endl;
    cout << "The cosine of x plus y divided by z is: " << cosine_plus_some(x,y,z) << endl;
    cout << "The average of x, y, and z is: " << average(x,y,z) << endl;
    cout << "The log base 2 of x is: " << log_base_2(x) << endl;
    return 0; //Deuces.
}
