#include <iostream>
//#include <windows.h>
//#include <MMsystem.h>


#include "Dog.h"


/**
    constructor for dog class that sets the name of the animal and its power_level_.
    Gives it "bark" and Mammals for its parent class constructor

    @param string name

*/
Dog::Dog(std::string name) : Animal("Bark!!", AnimalType::Mammals)
{
    name_ = name;
    power_level_ = 40;

}

/**
    Print outs the animals sound string

    Note: On windows sound will play if you uncomment second line and headers

    @param
    @return
*/
void Dog::MakeSound(){
    std::cout<<"\""<<this->Getsound()<<"\" said "<<this->get_name()<<".\n"<<std::endl;
    //PlaySound(TEXT("dogbark3.wav"), NULL, SND_SYNC);
};


/**
    Sets Animals HasPower to true, prints out the animals specific string and returns that animals power level

    @param
    @return power_level_
*/
int Dog::GetPower(){
    std::cout<<"The Dog has Gotten his Power!\n\n";
    HasPower = true;
    return power_level_;
};

