//Declaration
#ifndef MOVE_H
#define MOVE_H

using namespace std;

class Move {
    public:
        Move();
        Move(int x, int y, int size);
        Move(int new_score);
        int score;
        int reference;
};


#endif