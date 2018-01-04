//Class declaration
#pragma once //Ensures this file is only included once during compilation
using namespace std;

class EggCarton{
    public:
        EggCarton():brown_eggs(0), white_eggs(0){} //Default constructor, initializes member variable to 0
        //Two integer parameter constructor initializes member variables to parameters and if total value is greater than 12
        //then both variables are set to zero.
        EggCarton(int new_brown_eggs, int new_white_eggs):brown_eggs(new_brown_eggs), white_eggs(new_white_eggs){
            if((brown_eggs+white_eggs)>12){
                brown_eggs = 0;
                white_eggs = 0;
            }
        }
        //Function declarations
        bool addBrownEggs(int n);
        bool addWhiteEggs(int n);
        int getTotalEggs();
    private:
        int brown_eggs;
        int white_eggs;
};