#include <iostream>
#ifndef ANIMAL_H
#define ANIMAL_H

/*
using the idea of rock papers scissors in my fight function.

Mammals scare off Fish
Fish eat insects
Insects fly away from Mammals

Rock = Mammals; Paper = Insects ; Scissors = Fish;


*/

enum class AnimalType {Insect ,Fish ,Mammals};

std::string AnimalTypeStringfy(AnimalType a);

class Animal
{
    public:
        Animal(std::string sound, AnimalType t);

        //define inline
        virtual std::string get_name(){return name_;}
        virtual std::string get_Animal_string() { return animal_string_; }

        //defined inline
        AnimalType get_category_(){return category_;}
        std::string Getsound() { return sound_; }
        bool get_HasPower(){return HasPower;}


        virtual void MakeSound(){};
        Animal * Fight(Animal * a);
        virtual int GetPower(){ return power_level_;};

    protected:
        std::string name_;
        int power_level_;
        std::string animal_string_;
        bool HasPower = false;
    private:

        std::string sound_;
        AnimalType category_;
};

#endif // ANIMAL_H
