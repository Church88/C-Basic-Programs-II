#include <iostream>
#include <cstdlib>
using namespace std;

char color_values[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}; //Global array of hex characters

/**
Generates a random string of six hexidecimal characters
@return a random hexidecimal string
*/
string SelectHexChar(){
    string ret;
    for(int j = 0; j < 6; j++){ //Inner loop runs 6 times
            ret += (color_values[rand()%16]); //Print a random character from the array
        }
    return ret;
}

/**
Prints out a list of 100 random color values
*/
void PrintColorsHtml(){
    string hex_string;
    for(int i = 0; i < 100; i++){ //Outer loop runs 100 times
        hex_string = SelectHexChar();
        cout << "<li style=\"color: #" << hex_string << "\">" << hex_string << "</li>" << endl; //
    }
}

/**
Prints out html boiler plate with randome colors in the body
*/
void BoilerAndColors(){
    cout << "<html>\n" << 
    "<head>\n" << 
    "<title>Assignment 4 Exercise 4</title>\n" <<
    "</head>\n" <<
    "<body>\n" <<
    "<ol>\n";
    PrintColorsHtml();
    cout << "</ol>\n" <<
    "</body>\n" <<
    "</html>\n";
}

int main(){
    BoilerAndColors();
    return 0;
}
