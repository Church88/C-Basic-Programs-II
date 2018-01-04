#include <iostream>
#include <cassert>
#include <vector>
#include "count.h"
using namespace std;

int main(){
    //Vector of 10 10's
    vector <int> test_0 (10,10);
    assert(countOccurrences(test_0,10)==10);
    //Vector with no duplicates
    vector <int> test_1;
    for(int i = 0; i < 10; i++){
        test_1.push_back(i);
    }
    assert(countOccurrences(test_1,9)==1);
    //Vector that does not have check value
    vector <int> test_2 (10,13);
    assert(countOccurrences(test_2,12)==0);
    return 0;
}