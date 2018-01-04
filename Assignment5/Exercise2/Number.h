//Class Declaration
#pragma once //Ensure this file is only included once during compilation
using namespace std;

class Number{
    public:
        Number(int n):number(n){} //Single parameter constructor sets number to the value of the parameter
        //Function declarations
        bool isPrime();
        bool isDivisibleBy(int n);
        void printPrimesToNumber();
    private:
        int number;
};