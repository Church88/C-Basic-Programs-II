#include <iostream>
#include <vector>
#include <cassert>
#include "vectorcheck.h"
using namespace std;

int main(){
    vector<int> test_0 (10,10);
    vector<int> test_1 (12,12);
    vector<int> test_2 (10,10);
    vector<int> test_3 (10,11);
    assert(areIdentical(test_0,test_2));
    assert(!areIdentical(test_0,test_1));
    assert(!areIdentical(test_0,test_3));
    return 0;
}