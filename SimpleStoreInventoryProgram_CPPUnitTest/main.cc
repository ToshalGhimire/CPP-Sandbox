/*
    Toshal Ghimire
    written design with pujan 

    This Program uses TextUI with a store class private field
    that priviate field has all the functions needed to mange cart and inventory


*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Store.h"
#include "TextUI.h"
#include "Cart.h"
#include "Item.h"



int main(int argc, char **argv){
    
    std::cout<< "\nMain is running\n" << std::endl;
    
    TextUI * B  = new TextUI(argv);
    B->Start();



}