#include <iostream>
//#include <windows.h>
//#include <MMsystem.h>

#include "Shark.h"

/**
    constructor for dog class that sets the name of the animal and its power_level_.
    Gives it "Splash" and Fish for its parent class constructor

    @param string name

*/
Shark::Shark(std::string name) : Animal("Splash!!",AnimalType::Fish)
{
    name_ = name;
    power_level_ = 60;

}

/**
    Print outs the animals sound string

    Note: On windows sound will play if you uncomment second line and headers

    @param
    @return
*/
void Shark::MakeSound(){
    std::cout<<"\""<<this->Getsound()<<"\" said "<<this->get_name()<<".\n"<<std::endl;
//    PlaySound(TEXT("Shark.wav"), NULL, SND_SYNC);
//    PlaySound(TEXT("Bite.wav"), NULL, SND_SYNC);
};

/**
    Sets Animals HasPower to true, prints out the animals specific string and returns that animals power level

    @param
    @return power_level_
*/
int Shark::GetPower(){
    std::cout<<"The Shark has Gotten his Power!\n\n";
    HasPower = true;
    return power_level_;
};
