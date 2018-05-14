#ifndef CART_H
#define CART_H

#include <string>
#include <iostream>
#include <vector>

#include "Item.h"

class Cart
{
    public:
        Cart();
        std::vector<Item*> get_cart(){return cartItems_;}

        void DisplayCart(bool showList = false);
        bool Contains(Item * temp);
        
        void IncAmmout(Item * temp);
        //void DecAmmount(Item * temp);

        void Add2Vector(Item * temp){cartItems_.push_back(temp);}
        void RemoveFromVector(int index);

        std::string ReturnName(int index) {return cartItems_[index-1]->get_name();}
        int CartSize(){ return cartItems_.size();}

        double CartPrice();
        void ClearCart();

        bool IsEmpty();



    private:
        std::vector<Item*> cartItems_;

};



#endif //CART_H