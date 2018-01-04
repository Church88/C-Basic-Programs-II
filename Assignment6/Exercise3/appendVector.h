#include <vector>
using namespace std;

/**
 * Append one vector to another
 * @param vector<int> &v will have another vector appended to it
 * @param vecotr<int> &w the vector that will be tacked on to v
*/
void appendVector(vector<int> & v, const vector<int> & w){
    for(int i = 0; i < w.size(); i++){
        v.push_back(w.at(i));
    }
    return;
}