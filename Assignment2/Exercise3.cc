#include <iostream> 
#include <cstdlib> //For using the rand() funciton
using namespace std;

int main() {
    for(int i = 0; i < 100; i++){//Run a loop 100 times.
        srand(time(NULL)+i); //Seed the number generator with the system time plus the iteration of the loop. Thus a different list should be generated each time it runs.
        cout << "# " << i+1 << "\t" << rand() << endl; //Basic output formatting to make sure all 100 are displayed.
    }
    return 0; //Audii.
}