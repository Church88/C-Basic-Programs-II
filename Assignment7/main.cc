#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cstdlib>
#include <sstream>
#include "board.h"
#include "ai.h"
using namespace std;

//Some constants for the four different markers on the board
const char HUMAN = 'X';
const char AI_MARK = 'O';
const char EMPTY = ' ';
const char NO_WIN = '_';

/**Helper function to capitalize input string
 * @param string &str the input string to be capitalized
*/
void upperCaseify(string &str){
    for(int i = 0; i < str.size(); i++){//Iterate over the string
        str.at(i) = toupper(str.at(i)); //Capitalize each character
    }
}
/**Prints out the introductory infromation for the player
*/
void printGreeting(){
    cout << "\tWelcome to the impossible game of Tic Tac Toe!\n\n";
    cout << "The board on the left represents the game board and the one on the right\n";
    cout << "shows the correpsonding inputs for each position. To make a move simply enter the\n";
    cout << "number of the position you desire. At anytime you can exit the game by typing 'quit'\n\n";
    cout << "Human moves will be " << HUMAN << " and AI moves will be " << AI_MARK << endl;
    cout << "\nBe warned the AI will never lose.\n\nWould you like to make the first move ('yes' or 'no'): "; 
}
/**Controls the check conditions after each move checking for a win and handling reset conditions
 * @param bool &reset will be set to true if there is an endgame condition and the user wants to play again
 * @param Board &board is passed in to be handed over to the winReset function and to execute the checkWin funtion
*/
void helperCheck(bool &reset, Board &board){
    char winner = board.checkWin();
    if(winner != NO_WIN){
        if(winner == EMPTY){
            cout << "Cats game!\n";
        }
        else {
            cout << "Winner is: " << winner << "! Thanks for playing.\n";
        }
        cout << "Would you like to play again? ('yes' or 'no'): ";
        while(true){
            string input;
            getline(cin,input);
            upperCaseify(input);//Capitalize to avoid minor user error
            if(input == "YES"){
                reset = true;
                return;
            }
            if(input == "NO"){//This is how the user exits the game
                system("clear");
                exit(EXIT_SUCCESS);//Exit program
            }
            if(input == "QUIT"){//Always a way out
                system("clear");
                exit(EXIT_SUCCESS);
            }
            else{
                cout << "Bad input please enter 'yes' or 'no'\n"; //Allow user to reenter selection
                continue;
            }
        }
    }
}
/**The primary game loops and logic for running Tic Tac Toe. The game is made up of a Board and an AI. Main is as much a function as a semi truck is a sedan.
 * @return int 0 if everything executed successfully otherwise it can return all manner of values based on the particular error
 * which can be referenced from other programs running this program
*/
int main(){
    Board board(HUMAN,AI_MARK,EMPTY,NO_WIN);
    AI dave(HUMAN,AI_MARK,EMPTY,NO_WIN);
    bool human_first = true;
    while(true){
        board.clearBoard(); //Clear the board
        system("clear"); //Clear the screen
        board.printBoard(); //Print the board and reference board
        printGreeting(); //Print out the inital game text and prompt
        string input;
        while(true){
            getline(cin,input);//Grab a line of input
            upperCaseify(input);//Uppercase the input to avoid common errors
            if(input == "YES"){
                human_first = true;
                break;
            }
            if(input == "NO"){
                human_first = false;
                break;
            }
            if(input == "QUIT"){//Provide a way out
                system("clear");
                exit(EXIT_SUCCESS);
            }
            else{
                cout << "Bad input, try again\n";//All other entries will recycle the loop
                continue;
            }
        }
        if(!human_first){//Handle the initial move
            int rand_ai_move = dave.aiFirstMove(MAX_SIZE); //Capture the reference value of a random corner or the center
            board.makeMove(rand_ai_move,AI_MARK); //Place the move on the board
        }
        system("clear"); //Clear screen
        board.printBoard(); //Print board and reference board
        bool reset = false; //Flag for resetting the game after a tie or win
        while(true){//Secondary loop to run the move sequences
            int input = 0;
            string str;
            while(true){
                cout << "Your move human: ";
                stringstream ss; 
                getline(cin,str);//Capture entered value in a string
                ss << str; //Read the string into the stringstream
                upperCaseify(str); //Uppercase the string to avoid ambiguity
                if(str == "QUIT"){//Always allow the user to exit
                    system("clear");
                    exit(EXIT_SUCCESS);
                }
                ss >> input;//Read the stream into the int
                if(input < 1 || input > (MAX_SIZE*MAX_SIZE)){ //Validate the range of the int
                    cout << "Bad input please select a value from the reference board\n";
                    continue;
                }
                bool valid_move = board.makeMove(input,HUMAN); //makeMove will return false if the spot is taken
                if(!valid_move){
                    cout << "That spot is already taken try again.\n";
                    continue;
                }
                break;
            }
            system("clear"); //Clear scree
            board.printBoard(); //Print boards
            helperCheck(reset,board);//After every move the helperCheck function will run
            if(reset){ //If the reset flag was tripped we want to break out to the main loop to restart the game
                break;
            }
            dave.aiMakeMove(board);//The AI makes a move
            system("clear"); //Clear screen
            board.printBoard(); //Print boards
            helperCheck(reset,board); //Board has to be analyzed again and user makes a choice if the game is over
            if(reset){//Once again is the user wishes to play again once game is over this may be tripped
                break;
            }
        }
    }
    return 0; //Exit success
}