#ifndef CAT_H
#define CAT_H

#include "Animal.h"


class Cat : public Animal
{
    public:
        Cat(std::string name);

        std::string get_name(){return name_;}
        std::string get_Animal_string() { return animal_string_; }

        void MakeSound();
        int GetPower();


    private:
        std::string name_;
        std::string animal_string_ = "Cat";
};

#endif // CAT_H
