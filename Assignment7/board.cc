#include "board.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**Primary constructor setting up the markers and the size, also set winner to NULL
 * @param char new_human is the human player marker
 * @param char new_ai is the ai player marker
 * @param char new_empty is the empty marker
 * @param char new_nowin is the no win character
*/
Board::Board(char new_human, char new_ai, char new_empty, char new_nowin){
    HUMAN_CHAR = new_human;
    AI_CHAR = new_ai;
    EMPTY_CHAR = new_empty;
    NO_WIN = new_nowin;
    SIZE = MAX_SIZE; //SIZE is used within the class, however MAX_SIZE is used to set up the boards themselves so it is a global
}
/**Returns the char at a position on the board
 * @param int i is the row
 * @param int j is the column
 * @return is the character at that position
*/
char Board::boardAccess(int i, int j) const{
    return board[i][j];
}
/**Getter for the board size
 * @return int the size of the board
*/
int Board::getSize() const{
    return SIZE;
}
/**Sets a position to a specific player marker
 * @param int i is the row
 * @param int j is the column
 * @param char player is the player marker
*/
void Board::setPos(int i, int j, char player){
    board[i][j] = player;
    return;
}
/**Function prints out the game board and associated reference board with spacing
*/
void Board::printBoard() const {
    for(int i = 0; i < SIZE; i++){
        cout << "\t|";
        for(int j = 0; j < SIZE; j++){
            cout << " " << board[i][j] << " |"; //Game board print out
        }
        cout << "\t\t|";
        for(int k = 0; k < SIZE; k++){
            cout << " " << ref_board[i][k] << " | "; //Reference board print out
        }
        cout << endl;
    }
}
/**Function will set all positions on the main board to blank and assign appropriate values to the reference board
*/
void Board::clearBoard(){
    int count = 1;//Extra int for assigning values to the reference board
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            board[i][j] = EMPTY_CHAR; //Blank out positions on the game board
            ref_board[i][j] = count; //Set values on the reference board
            ref_values.push_back(make_pair(i,j)); //Assign the corrdinates to the reference vector
            count++; //Iterate the count
        }
    }
}
/**Take a reference value and execute the move, this is for outside classes to affect the board (eg the AI)
 * @param int ref is the integer value associated with the reference position on the board
 * @param char player is the player's character making the move
 * @return bool if the spot was empty and the position is take it returns true otherwise false
*/
bool Board::makeMove(int ref, char player){
    pair<int,int> pos = ref_values.at(ref-1); //Capture the coordinates of one of the best moves
    if(board[pos.first][pos.second] == EMPTY_CHAR){
        board[pos.first][pos.second] = player;//Assign the move to the board based on the position from the reference
        return true;
    }
    return false;
}
/**Check for win conditions and return the character of the winner
 * @return char will be the winner's character, no_win or the empty char to denote a tie
*/
char Board::checkWin(){
    string human;//Two strings to be populated to the correct length
    string ai;
    for(int i = 0; i < SIZE; i++){//Populate strings with the correct char for each player
        human += HUMAN_CHAR;
        ai += AI_CHAR;
    }
    string horizontal_check; //All four different possible win configurations
    string vertical_check;
    string diagonal_left_check;
    string diagonal_right_check;
    int count = SIZE-1; //Implement another interating int for the loop
    bool full = true; //Full board flag
    for(int i = 0; i < SIZE; i++){
        diagonal_left_check += board[i][count]; //Capture diagonal left
        diagonal_right_check += board[i][i]; //Capture diagonal right
        for(int j = 0; j < SIZE; j++){
            if(board[i][j] == EMPTY_CHAR){//If there is an open spot set full to false
                full = false;
            }
            horizontal_check += board[i][j];//Capture the row
            vertical_check += board[j][i];//Capture the column
        }
        if(horizontal_check == ai || vertical_check == ai){ //Check horizontal and vertical after each iteration of the inside loop
            return AI_CHAR;
        }
        if(horizontal_check == human || vertical_check == human){
            return HUMAN_CHAR;
        }
        horizontal_check = ""; //Reset the strings after each inner iteration
        vertical_check = "";
        count--; //Count down as i increases to capture the other diagonal
    }
    if(diagonal_left_check == human || diagonal_right_check == human){//Check both diagonals
        return HUMAN_CHAR;
    }
    if(diagonal_left_check == ai || diagonal_right_check == ai){
        return AI_CHAR;
    }
    if(full){ //The board is full at this point no winner has been returned thus it is a tie game
        return EMPTY_CHAR;
    }
    return NO_WIN; //Return the NO_WIN char if nothing else triggered
}
