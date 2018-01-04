#include <iostream>
#include <cassert>
#include "twodeecheck.h"
using namespace std;

int main(){
    int arr[10][20];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            arr[i][j] = 0;
        }
    }
    assert(isAllZeros(arr)); //Check array of all zeroes
    arr[0][0] = 1;
    assert(!isAllZeros(arr)); //Check array with a one in it
    return 0;
}