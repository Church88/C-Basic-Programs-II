#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
    cout << "Enter a whole number to sum: "; //Prompt user
    int n;
    cin>>n; 
    if(!cin){//User input checked to make sure a number is coming in, if not quit program.
        cout << "Bad input\n";
        exit(EXIT_FAILURE); //Exit program signalling that the application failed.
    }
    int sum = 0; //Set up an int to hold the summation.
    for(int i = 0; i <= n; i++){
        sum+=i; //Using the value of i to incrementally add to sum.
    }
    cout << sum << endl;
    return 0;
}