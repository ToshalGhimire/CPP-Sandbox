/*

Toshal Ghimire
PE 4 - Innheritance Animal


using the idea of rock papers scissors in my fight function.(Rock = Mammals, Paper = Insects, Scissors = Fish)

Mammals scare off Fish
Fish eat insects
Insects fly away from Mammals

GetPower is a virtual returns the animals power_level_ int with its custom output string for each animal


Important:
    #include <windows.h> & #include <MMsystem.h> and PlaySound(TEXT("dogbark3.wav"), NULL, SND_SYNC) inside the virtual function MakeSound() in
    all cpp files have all been commented out, this is beacuse the grading is done on Linux. I coded this assignment on windows and they only work
    on windows OS.

    Basically these function, if uncommented out on windows, will play a wav audio file of the specific animals sound in the console if MakeSound()
    is called

*/


#include <iostream>
//#include <windows.h>
//#include <MMsystem.h>

#include "Dog.h"
#include "Animal.h"
#include "Cat.h"
#include "Shark.h"
#include "Bug.h"
using namespace std;

int main()
{
    //making three animal objects
    Animal * AOne;
    Animal * ATwo;
    Animal * AThree;
    Animal * AFour;

    //Making a Dog, Bug and Shark, Cat object
    Dog D("Rex");
    Bug B("Fly");
    Shark S("Jaws");
    Cat C("Tom");

    //Setting them to the animal object
    AOne = &D;//Dog
    ATwo = &B;//Bug
    AThree = &S;//Shark
    AFour = &C;//Cat


    AOne->MakeSound();

    ATwo->GetPower();

    AThree->Fight(AFour);

    return 0;
}
