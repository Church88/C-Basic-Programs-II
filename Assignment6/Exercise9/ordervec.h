using namespace std;


/**Function determines if a vector contains only increasing integers
 * @param vector<int> v is the vector to be evaluated
 * @return bool will be true if vector contains only increasing integers and false otherwise
*/
bool isStrictlyIncreasing(const vector<int> & v){
    int previous = v.at(0);
    for(int i = 1; i < v.size(); i++){
        if(v.at(i)<=previous){
            return false;
        }
    }
    return true;
}