#include "Animal.h"


/**
    constructor sets animal sound and animal type

*/
Animal::Animal(std::string sound, AnimalType t)
{
    sound_ = sound;
    category_ = t;
}

/**
    This function takes the idea of rock paper scissor and replaces it with the type of animal and returns the winner Animal *
    (ie Rock = Mammals , Paper = Insects , Scissors = Fish)

    @param Animal Pointer of the animal your fighting
    @return The winning Animal pointer
*/
Animal * Animal::Fight(Animal * a){
    std::cout<<"\n< A fight has started! >\n";
    std::cout<<"\n\t"<<this->get_name()<<" ("<<this->GetPower()<<")"<<" VS "<< a->get_name()<<" ("<<a->GetPower()<<")";
    std::cout<<"\n--------------------------------\n";

    //the if-else for the rock paper scissors implementation
    if (this->get_category_() == a->get_category_()){
        std::cout<<"This fight is a draw!"<<std::endl;
        std::cout<<"Two "<<AnimalTypeStringfy(this->category_)<<" are equaly matched!"<<std::endl;

    }else if (this->get_category_() == AnimalType::Fish && a->get_category_() == AnimalType::Insect){
        std::cout<<this->get_name()<<" has won the fight!"<<"\nFish eat Insects!\n"<<std::endl;
        this->MakeSound();
        return this;

    }else if (this->get_category_() == AnimalType::Fish && a->get_category_() == AnimalType::Mammals){
        std::cout<<a->get_name()<<" has won the fight!"<<"\nMammals scare off Fish!\n"<<std::endl;
        a->MakeSound();
        return this;

    }else if (this->get_category_() == AnimalType::Insect && a->get_category_() == AnimalType::Mammals){
        std::cout<<this->get_name()<<" has won the fight!"<<"\nInsects fly away from mammals!\n"<<std::endl;
        this->MakeSound();
        return this;

    }else if (this->get_category_() == AnimalType::Insect && a->get_category_() == AnimalType::Fish){
        std::cout<<a->get_name()<<" has won the fight!"<<"\nFish eat insects!\n"<<std::endl;
        a->MakeSound();
        return this;

    }else if (this->get_category_() == AnimalType::Mammals && a->get_category_() == AnimalType::Insect){
        std::cout<<a->get_name()<<" has won the fight!"<<"\nInsects fly away from mammals!\n"<<std::endl;
        a->MakeSound();
        return this;

    }else if (this->get_category_() == AnimalType::Mammals && a->get_category_() == AnimalType::Fish){
        std::cout<<this->get_name()<<" has won the fight!"<<"\nMammals scare off Fish!\n"<<std::endl;
        this->MakeSound();
        return this;

    }else {
        std::cout<<"Invalid Animal Category!\nReturning the calling object.\n"<<std::endl;
        return this;

    }

    return 0;

};

/**
    stringfy the enum class AnimalType

    @param AnimalType
    @return string

*/
std::string AnimalTypeStringfy(AnimalType a){
    switch(a){
    case AnimalType::Insect: return "Insect";
    case AnimalType::Fish: return "Fish";
    case AnimalType::Mammals: return "Mammals";
    default: return "";
    }
};
