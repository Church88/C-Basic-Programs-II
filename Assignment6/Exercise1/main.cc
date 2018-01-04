#include <iostream>
#include <cassert>
#include "maxval.h"
using namespace std;

int main(){
    //Max value is a negative
    int arr_0[5] = {-1,-3,-4,-7,-8};
    assert(mymaximum(arr_0,5)==-1);
    //Max value is first value
    int arr_1[5] = {10,3,9,-3,-10};
    assert(mymaximum(arr_1,5)==10);
    //Max value is last value
    int arr_2[5] = {2,0,-10,45,55};
    assert(mymaximum(arr_2,5)==55);
    return 0;
}