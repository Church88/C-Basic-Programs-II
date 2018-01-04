//Class Declaration
#pragma once //Ensure this file is included once during compilation
using namespace std;

class Number{
    public:
        Number(int n):number(n){} //Constructor sets value of number to the parameter
        //Function declarations
        bool isPrime();
        bool isDivisibleBy(int n);
    private:
        int number;
};