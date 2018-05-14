#include "Cart.h"

Cart::Cart(){

};


/*
    display cart that has an optional boolean paramater, if the paramater is set to true
    then the function prints the cart but with numbers (for selecting purposes)

    @param bool
    @return void

*/
void Cart::DisplayCart(bool showList){
    if (showList){
        int counter = 1;
        std::cout << "\nCART:"<< std::endl;
        for(auto a : cartItems_){
            std::cout << " (" << counter++ << ") " << a->DisplayItem();
        }
        std::cout << std::endl;

    }else {

        std::cout << "\nCART:"<< std::endl;
        for(auto a : cartItems_){
            std::cout << a->DisplayItem();
        }
        std::cout << std::endl;

    }

};

/*
    Removes a item from cart
    if item quantity is greater then 1 then we --
    else we erase the item from vector 

    @param index
    @return void

*/
void Cart::RemoveFromVector(int index){
    if(cartItems_[index-1]->get_quanity() > 1){
        cartItems_[index-1]->Dec();
    }else{
        cartItems_.erase(cartItems_.begin() + index -1);

    }
};

/*
    Checks if your cart contains the item given to it

    @param Item 
    @return bool

*/
 bool Cart::Contains(Item * temp){
     for(auto b : cartItems_){

         if (temp->get_type() == b->get_type()){
             if(temp->get_name() == b->get_name()){
                 return true;
             }
         }

     }
     return false;
 };


/*
    Checks if your cart contains an item, if it does increase the item quanity 

    @param Item 
    @return void

*/
void Cart::IncAmmout(Item * temp){


    if(this->Contains(temp)){
        for(auto& i: cartItems_){
            if (i->get_name() == temp->get_name()){
                i->Inc();
            }
        }
        
    
    }else{
        std::cout << "Your cart does not contain " << temp->get_name() <<"!\n";
    }
    
};

//ended up not using this method but didnt want to remove it 
/*
    Checks if your cart contains an item, if it does decrease the item quanity 

    @param Item 
    @return void
*/
// void Cart::DecAmmount(Item * temp){


//     if(this->Contains(temp)){
//         std::cout << "You removed one " << temp->get_name() <<" From your Cart!\n";

//         for(auto& i: cartItems_){
//             if (i->get_name() == temp->get_name()){
//                 i->Dec();
//             }
//         }

//         this->DisplayCart();

//     }else{
//         std::cout << "Your cart does not contain " << temp->get_name() <<"!\n";
//     }
    

// };


/*
    calcuates the price of all things inside the cart 

    @param none
    @return double

*/
double Cart::CartPrice(){
    double total = 0 ;
    double taxRate = 1.0845;
    for (auto a : cartItems_){

        if(a->get_type() == ItemType::Food){
            total += (((a->get_price() * taxRate) * a->get_quanity()) * a->get_discount());
        }else if(a->get_type() == ItemType::Clothes){
            total += (((a->get_price() * taxRate) * a->get_quanity()) * a->get_discount());

        }else if(a->get_type() == ItemType::Tech){
            total += (((a->get_price() * taxRate) * a->get_quanity()) * a->get_discount());
        }
    }
    return total;
};


// below are just vector helper methods for  a private vector

//clears cart item
void Cart::ClearCart(){
    cartItems_.clear();
};

//checks if empty
bool Cart::IsEmpty(){
    return cartItems_.empty();
};