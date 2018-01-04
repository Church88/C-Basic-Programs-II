using namespace std;


/**Function will determine if two vectors are identical
 * @param vector<int> a one of two vectors to be compared
 * @prarm vector<int> b the second vector to be compared
 * @return bool false if the vectors are not the same and true otherwise
*/
bool areIdentical(const vector<int> & a, const vector<int> & b){
    if(a.size()==b.size()){ //Only if the vectors are of the same size can they be identical
        for(int i = 0; i < a.size(); i++){
            if(a.at(i)!=b.at(i)){
                return false; //If any values are not the same
            }
        }
        return true;
    }
    return false;
}