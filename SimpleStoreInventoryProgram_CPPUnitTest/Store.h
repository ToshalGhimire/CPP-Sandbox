#ifndef STORE_H
#define STORE_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>


#include "Item.h"
#include "Cart.h"



class Store
{

    public:
        Store(char **argv);

        std::string get_StoreName() {return store_name_;}
        void DisplayInventory(bool showList = false);

        void AddItemToCart();
        void RemoveItemFromCart();
        void Checkout();
        
        void leave();
        void OutputFile();


    private:
        std::string store_name_ = "";
        std::vector<Item*> inventory_;

        Cart * mycart_ = new Cart();


        

};



#endif //STORE_H