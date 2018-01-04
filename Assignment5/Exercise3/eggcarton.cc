//EggCarton implementation
#include "eggcarton.h"
using namespace std;
/**
 * Function to return the total number of eggs in an EggCarton
 * return the integer value of all the eggs
*/
int EggCarton::getTotalEggs(){
    return this->brown_eggs+this->white_eggs;
}
/**
 * Adds an integer value to the BrownEggs
 * @param int n the value to be added to BrownEggs
 * @retrun bool if true the value was added else the input is invalid
*/
bool EggCarton::addBrownEggs(int n){
    if((this->getTotalEggs()+n)<=12){
        this->brown_eggs+=n;
        int check = this->brown_eggs;
        if(check < 0){
            this->brown_eggs = 0;
        }
        return true;
    }
    return false;
}
/**
 * Adds an integer value to WhiteEggs
 * @param int n the value to be added to WhiteEggs
 * @return bool if true the value was added else the input is invlid
*/
bool EggCarton::addWhiteEggs(int n){
    if((this->getTotalEggs()+n)<=12){
        this->white_eggs+=n;
        int check = this->white_eggs;
        if(check < 0){
            this->white_eggs = 0;
        }
        return true;
    }
    return false;
}