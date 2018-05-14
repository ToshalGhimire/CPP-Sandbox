#ifndef BUG_H
#define BUG_H

#include "Animal.h"


class Bug : public Animal
{
    public:
        Bug(std::string name);

        std::string get_name(){return name_;}
        std::string get_Animal_string() { return animal_string_; }

        void MakeSound();
        int GetPower();

    private:
        std::string name_;
        std::string animal_string_ = "Bug";
};


#endif // BUG_H
