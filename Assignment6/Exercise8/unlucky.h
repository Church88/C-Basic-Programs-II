#include <vector>
using namespace std;


/**Function scans vector for the integer 13 and returns true if it is present
 * @param vector<int> v is the vector to be evaluted
 * @return bool true if 13 is present in the vector and false otherwise
*/
bool isUnlucky(vector<int> & v){
    for(int i = 0; i < v.size(); i++){
        if(v.at(i) == 13){
            return true;
        }
    }
    return false;
}