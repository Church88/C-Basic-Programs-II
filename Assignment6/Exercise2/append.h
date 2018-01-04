#include <vector>
using namespace std;

/**
 * Append a range of integers from 0 to n-1 to a vector
 * @param vector<int> &v a reference to the vector values will be appended to
 * @param int n the number of values to be added, going from 0 to n-1
*/
void append(vector<int> & v, int n){
    for(int i = 0; i < n; i++){
        v.push_back(i);
    }
    return;
}