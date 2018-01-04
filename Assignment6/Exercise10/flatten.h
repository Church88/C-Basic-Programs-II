#include <vector>
using namespace std;

/**Function takes a 2D array and returns a 1D vector
 * @param int a[10[20] the array to be converted
 * @return ret is the vector representing the 2D array
*/
vector<int> flatten(int a[10][20]){
    vector <int> ret;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            ret.push_back(a[i][j]);
        }
    }
    return ret;
}