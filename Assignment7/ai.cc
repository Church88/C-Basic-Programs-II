#include <cstdlib>
#include <ctime>
#include <iostream>
#include "ai.h"
#include "move.h"
using namespace std;

/**Main constructor, the AI needs to know what characters represent each marker
 * @param char new_human is the human player marker
 * @param char new_ai is the ai player marker
 * @param char new_empty is the empty marker
 * @param char new_nowin is the no win character
*/
AI::AI(char new_human, char new_ai, char new_empty, char new_nowin){
    AI_CHAR = new_ai;
    HUMAN_CHAR = new_human;
    EMPTY_CHAR = new_empty;
    NO_WIN = new_nowin;
}
/**Implementation of the Minimax algorithm to determine best move for the AI
 * @param char player is the current player making a move
 * @param Board &board is the board object in its current state to be evaluated
 * @return Move is a move object that is the best move for the player that was passed in
*/
Move AI::miniMax(char player, Board &board){
    char winner = board.checkWin();//Capture the winner
    if(winner != NO_WIN){//If the winner is NO_WIN then no one won and it isn't a tie game
        if(winner == AI_CHAR){//Figure out who won and return the score based on the player, or zero if its a tie
            return Move(100);
        }
        if(winner == HUMAN_CHAR){
            return Move(-100);
        }
        if(winner == EMPTY_CHAR){//Otherwise it is a tie game
            return Move(0);
        }
    }
    vector<Move> moves;//Vector to store all possible moves
    for(int i = 0; i < board.getSize(); i++){//Iterate over the board
        for(int j = 0; j < board.getSize(); j++){
            if(board.boardAccess(i,j) == EMPTY_CHAR){//If the spot is open
                Move move(i,j,board.getSize());//Make a move for that position
                board.setPos(i,j,player);//Assign that position to the player
                if(player == AI_CHAR){//If this was the AI player's move
                    move.score = miniMax(HUMAN_CHAR, board).score;//The move's score is set to the value of the result of the function which will ultimately score that move
                }
                else{
                    move.score = miniMax(AI_CHAR, board).score;//Same procedure for the simulated human moves
                }
                moves.push_back(move);//Push the move onto the vector
                board.setPos(i,j,EMPTY_CHAR);//Reset the move 
            }
        }
    }
    int best_move = 0; //Capture the index of the best move
    int best_score = 0; //Find the best score
    if(player == AI_CHAR){//Max player
        best_score = -999;//Ensure the first positive value is assigned
        for(int i = 0; i < moves.size(); i++){
            if(moves.at(i).score > best_score){//Find max value
                best_score = moves.at(i).score;
                best_move = i;
            }
        }
    }
    else {//Min player or the Human player
        best_score = 999;
        for(int i = 0; i < moves.size(); i++){
            if(moves.at(i).score < best_score){//Find min value
                best_score = moves.at(i).score;
                best_move = i;
            }
        }
    }
    return moves.at(best_move);//Return the best move
}
/**Executes the AI move after determining the best position running minimax then executing it on the board
 * @param Board &board the board object to be passed on to the minimax function
*/ 
void AI::aiMakeMove(Board &board){
    board.makeMove(miniMax(AI_CHAR,board).reference,AI_CHAR);
    return;
}
/**Executes a random first move for the AI if the human player declines to go first
 * @param int size is the size of the board
 * @return int is the reference position of the move
*/
int AI::aiFirstMove(int size){
    int best_moves[] = {1,size,(1+(size*(size-1))),size*size,(((size*size)/2)+1)}; //Capture the corners and middle positons according to the reference values
    srand(time(0));//We want a random position to make the game more interesting
    return best_moves[rand()%5]; //Return that move (the move is a reference value to the desired position)
}