#include <cstdlib>
using namespace std;

/**
 * Scans an array of integers and returns the largest element
 * @param int a[] the array to be scanned
 * @param int numberoOfElements the size of the array
 * @return int ret the largest value found in the array 
*/
int mymaximum(int a[], int numberOfElements){
    int ret = a[0];
    for(int i = 1; i < numberOfElements; i++){
        if(a[i]>ret){
            ret = a[i];
        }
    }
    return ret;
}