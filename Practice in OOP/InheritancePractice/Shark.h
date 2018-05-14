#ifndef SHARK_H
#define SHARK_H

#include "Animal.h"


class Shark : public Animal
{
    public:
        Shark(std::string name_);

        std::string get_name() { return name_; }
        std::string get_Animal_string() { return animal_string_; }

        void MakeSound();
        int GetPower();

    protected:

    private:
        std::string name_;
        std::string animal_string_ = "Shark";
};

#endif // SHARK_H
