#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "Animal.h"


class Dog: public Animal
{
    public:
        Dog(std::string name);

        std::string get_name(){return name_;}
        std::string get_Animal_string() { return animal_string_; }

        void MakeSound();
        int GetPower();


    private:

        std::string name_;
        std::string animal_string_ = "Dog";
};



#endif // DOG_H
