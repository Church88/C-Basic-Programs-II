#include <iostream>
#include <cassert>
#include <vector>
#include "append.h"
using namespace std;

int main(){
    //Append nothing
    vector <int> test_0 (5,10);
    append(test_0,0);
    assert(test_0.size()==5);
    //Append 1 element
    append(test_0,1);
    assert(test_0.back() == 0);
    //Append 10 elements
    vector <int> test_1;
    append(test_1,10);
    for(int i = 0; i < 10; i++){
        assert(test_1.at(i) == i);
    }
    return 0;
}