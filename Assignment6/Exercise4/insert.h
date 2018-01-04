#include <vector>
using namespace std;


/**
 * Insert an integer into a sequenced vector while preserving the sequence
 * @param vector<int> &v the sequenced vector the integer will be inserted into
 * @param int k the integer that will be inserted
*/
int insert(vector<int> & v, int k){
    v.push_back(k); //Append the value to the end of the vector
    int temp = 0;
    for(int i = v.size()-2; i > -1; i--){ //Iterating from the end to the beginning
        if(v.at(i)>k){ //If the next value is larger we want to swap it with k
            temp = v.at(i); //Generic swap operation
            v.at(i) = k;
            v.at(i+1) = temp;
        }
    }
    return 0;
}