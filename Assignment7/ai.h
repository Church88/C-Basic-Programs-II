//Declaration
#ifndef AI_H
#define AI_H

#include "board.h"
#include "move.h"

using namespace std;

class AI {
    public:
        AI(char new_human, char new_ai, char new_empty, char new_nowin);
        void aiMakeMove(Board &board);
        Move miniMax(char player, Board &board);
        int aiFirstMove(int size);
    private:
        char AI_CHAR;
        char HUMAN_CHAR;
        char EMPTY_CHAR;
        char NO_WIN;
};

#endif