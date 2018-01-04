#include <iostream>
#include <cstdlib>
using namespace std;
void die(){ //If something goes wrong just exit signalling a failure has occured..
	exit(EXIT_FAILURE);
}
int main(){
    cout << "Please enter a number between 1 and 99 inclusive (-1 to quit): "; //Prompt
    while(true){
        int input = 0;
        cin >> input;
        if(!cin) {
            die(); //User input cannot be trusted.
        }
        if(input == -1){//If the user wishes to exit the program.
            break;
        }
        if(input == 42){
            cout << "Always the right answer, also good number\n"; //42 is the answer to any and all questions.
        }
        if(input <= 0 || input >= 100){
            cout << "bad number\n"; //Brackets not needed for single line execution
        }
        else{
            cout << "good number\n"; 
        }
    }
    cout << "Thanks for playing\n"; //Signal that the program has finished.
    return 0;
}