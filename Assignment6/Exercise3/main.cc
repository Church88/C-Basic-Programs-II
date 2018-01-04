#include <iostream>
#include <vector>
#include <cassert>
#include "appendVector.h"
using namespace std;

int main(){
    //Append an empty vector with a vector containing elements
    vector <int> test_2 (10,9);
    vector <int> test_3;
    appendVector(test_2,test_3);
    assert(test_2.size()==10);
    //Append two vectors with elements
    vector <int> test_0 (5,5);
    vector <int> test_1 (4,4);
    appendVector(test_0,test_1);
    assert(test_0.size() == 9);
    //Append a vector with elements to an empty vector
    vector <int> test_4;
    vector <int> test_5(3,3);
    appendVector(test_4,test_5);
    assert(test_4.size()==3);
    return 0;
}
