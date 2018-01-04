#include <vector>
#include <cassert>
#include "unlucky.h"
using namespace std;

int main(){
    //Test a lucky array
    vector<int> lucky(10,10);
    assert(!isUnlucky(lucky));
    //Test an array of all 13's
    vector<int> unlucky(13,13);
    assert(isUnlucky(unlucky));
    //Test an array with one 13
    vector<int> vec (10,10);
    vec.push_back(13);
    assert(isUnlucky(vec));
    return 0;
}