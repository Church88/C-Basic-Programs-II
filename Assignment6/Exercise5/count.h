#include <vector>
using namespace std;

/**
 * Iterates over a vector and returns how many occurances of a specified integer 
 * @param const vector<int> &v the vector to be iterated across
 * @param int k the value that will be tallied every time it appears in the vector
 * @return int count the number of times int k appears in the vector
*/
int countOccurrences(const vector<int> & v, int k){
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        if(v.at(i)==k){
            count++;
        }
    }
    return count;
}