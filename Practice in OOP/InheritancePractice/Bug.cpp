#include <iostream>
//#include <windows.h>
//#include <MMsystem.h>
#include "Bug.h"


/**
    constructor for dog class that sets the name of the animal and its power_level_.
    Gives it "BZZZ" and Insect for its parent class constructor

    @param string name

*/
Bug::Bug(std::string name) : Animal("BZZZ!!",AnimalType::Insect)
{
    name_ = name;
    power_level_ = 20;
}

/**
    Print outs the animals sound string

    Note: On windows sound will play if you uncomment second line and headers

    @param
    @return
*/
void Bug::MakeSound(){
    std::cout<<"\""<<this->Getsound()<<"\" said "<<this->get_name()<<".\n"<<std::endl;
    //PlaySound(TEXT("bug.wav"), NULL, SND_SYNC);
};

/**
    Sets Animals HasPower to true, prints out the animals specific string and returns that animals power level

    @param
    @return power_level_
*/
int Bug::GetPower(){
    std::cout<<"The Bug has Gotten his Power!\n\n";
    HasPower = true;
    return power_level_;
};
