#include <vector>
#include <cassert>
#include <iostream>
#include "insert.h"
using namespace std;

int main(){
    vector <int> test_vec;
    for(int i = 0; i < 5; i++){
        test_vec.push_back(i);
    }
    //Test insert as last element
    insert(test_vec,5);
    assert(test_vec.back() == 5);
    //Test insert as first element
    insert(test_vec,-1);
    assert(test_vec.front() == -1);
    //Test insert as middle element
    insert(test_vec,3);
    assert(test_vec.at(5)==3);
    return 0;
}