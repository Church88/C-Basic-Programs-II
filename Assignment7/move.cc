//Implementation
#include "move.h"
using namespace std;

/**Default constructor, set score to 0 and reference to -1
*/
Move::Move(){
    score = 0;
    reference = -1;
}
/**Constructor for setting the reference value of a move
 * @param int x is the x coordinate
 * @param int y is the y coordinate
 * @param int size is the size of the board assuming it is a square
*/
Move::Move(int x, int y, int size){
    reference = ((x*size)+y)+1;
}
/**Constructor for just setting the score of a move
 * @param int new_score is the score to be assigned to the new Move
*/
Move::Move(int new_score){
    score = new_score;
}