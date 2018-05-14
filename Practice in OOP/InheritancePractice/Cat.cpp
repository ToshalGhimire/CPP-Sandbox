#include <iostream>
//#include <windows.h>
//#include <MMsystem.h>

#include "Cat.h"

/**
    constructor for dog class that sets the name of the animal and its power_level_.
    Gives it "Meow" and Mammals for its parent class constructor

    @param string name

*/
Cat::Cat(std::string name): Animal("Meow!!", AnimalType::Mammals)
{
    name_ = name;
    power_level_ = 30;
}

/**
    Print outs the animals sound string

    Note: On windows sound will play if you uncomment second line and headers

    @param
    @return
*/
void Cat::MakeSound(){
    std::cout<<"\""<<this->Getsound()<<"\" said "<<this->get_name()<<".\n"<<std::endl;
    //PlaySound(TEXT("catmeow.wav"), NULL, SND_SYNC);
};


/**
    Sets Animals HasPower to true, prints out the animals specific string and returns that animals power level

    @param
    @return power_level_
*/
int Cat::GetPower(){
    std::cout<<"The Cat has Gotten his Power!\n\n";
    HasPower = true;
    return power_level_;
};
