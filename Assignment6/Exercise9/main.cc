#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>
#include "ordervec.h"
using namespace std;

int main(){
    srand(time(NULL));
    vector<int> ordered;
    vector<int> descending;
    vector<int> random;
    vector<int> almost;
    for(int i = 0; i < 20; i++){ //Ordered vector set up
        ordered.push_back(i);
    }
    assert(isStrictlyIncreasing(ordered));
    for(int i = 20; i >= 0; i--){ //Descending vector set up
        descending.push_back(i);
    }
    assert(!isStrictlyIncreasing(descending));
    for(int i = 0; i < 20; i++){ //Random vector set up
        random.push_back(rand()%20+1); //Values from 1 to 20
    }
    assert(!isStrictlyIncreasing(random));
    ordered.at(9) = -4; //Modify the ordered vector so it is no longer of only increasing values
    assert(!isStrictlyIncreasing(ordered));
    return 0;
}