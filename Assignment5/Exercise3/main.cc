//Testing for EggCarton class
#include "eggcarton.h"
#include <iostream>
#include <cassert>
using namespace std;

int main(){
    EggCarton carton_1;//Check default constructor
    assert(carton_1.getTotalEggs()==0);
    EggCarton carton_2(2,3);//Check two int parameter constructor
    assert(carton_2.getTotalEggs()==5);
    //Check two int parameter constructor when total is > 12
    EggCarton carton_3(4,9);
    assert(carton_3.getTotalEggs()==0);
    //Check add too many white eggs
    carton_3.addWhiteEggs(13);
    assert(carton_3.getTotalEggs()==0);
    //Check add too many brown eggs
    carton_3.addBrownEggs(13);
    assert(carton_3.getTotalEggs()==0);
    //Check getTotalEggs
    carton_3.addBrownEggs(5);
    carton_3.addWhiteEggs(-10);
    cout << carton_3.getTotalEggs();
    assert(carton_3.getTotalEggs()==5);
    //Check getTotalEggs after modifying it
    return 0;
}