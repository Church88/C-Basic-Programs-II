#ifndef BOARD_H
#define BOARD_H

#include <vector>

const int MAX_SIZE = 3;

using namespace std;

class Board{
    public:
        Board(char new_human, char new_ai, char new_empty, char new_nowin);
        bool makeMove(int ref, char player);
        void setPos(int i, int j, char player);
        void clearBoard();
        char checkWin();
        char boardAccess(int i, int j) const;
        void printBoard() const;
        int getSize() const;
    private:
        char board[MAX_SIZE][MAX_SIZE];
        int ref_board[MAX_SIZE][MAX_SIZE];
        vector<pair<int,int> > ref_values;
        char HUMAN_CHAR;
        char AI_CHAR;
        char EMPTY_CHAR;
        char NO_WIN;
        int SIZE;
};

#endif