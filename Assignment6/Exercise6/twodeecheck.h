using namespace std;


/**Function will scan a 2D array and determine if all values are zero
 * @param int a[10][20] the array to be evaluated
 * @return bool will be true if all values are zero and false otherwise
*/
bool isAllZeros(int a[10][20]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            if(a[i][j]!=0){
                return false;
            }
        }
    }
    return true;
}