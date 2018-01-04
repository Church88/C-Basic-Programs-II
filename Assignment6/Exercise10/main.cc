#include <iostream>
#include "flatten.h"
#include <vector>
using namespace std;

int main(){
    int test[10][20];
    int count = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            test[i][j] = count; //Fill the array with the column value
            count++;
        }
        count = 0;
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            cout << test[i][j]; //Print out the 2D array in a block
        }
        cout << endl;
    }
    vector <int> result = flatten(test);
    for(int i = 0; i < 200; i++){
        cout << result.at(i); //Print out the vecotr as a single line
    }
    return 0;
}