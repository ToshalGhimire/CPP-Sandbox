#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Item.h"
#include "Store.h"
#include  "Cart.h"


/*

All of my functions in Store use the cart methods to minulpate the cart and inventory
so if these methods work, then so does my tests for store, that is why i exclude it

all my store methods, get user input and use it to call methods in cart and items
i realized while doing the test that this was bad design, that the TextUi should handle
all the user inputs, this was a mistake that was too late for me to fix, but i will program
diffrent for furture homeworks.

*/
TEST_CASE("Cart Function test", "[CART]")
{

    FOOD * Pizza = new FOOD("Pizza,10,1");
    FOOD * Burger = new FOOD("Burger,8,1");
    Cart *C = new Cart();
    C->Add2Vector(Pizza);

    SECTION("Check if another pizza exists in the cart.")
    {
        
        FOOD * Pizza1 = new FOOD("Pizza,12,1");

        REQUIRE(C->Contains(Pizza1) == true);
    }

    SECTION("Check if the Burger exists in the cart.")
    {
        REQUIRE(C->Contains(Burger) == false);
    }

    SECTION("Incerment the amount of Pizza by one from the cart.")
    {
        C->IncAmmout(Pizza);
        REQUIRE(C->get_cart()[0]->get_quanity() == 2);
    }

    SECTION("Decrement the amount of Pizza from the cart.")
    {
        C->IncAmmout(Pizza);
        C->RemoveFromVector(1);
        REQUIRE(C->get_cart()[0]->get_quanity() == 1);
    }

    SECTION("Decrement the amount of Pizza from the cart.")
    {
        C->RemoveFromVector(1);
        C->Contains(Pizza);
        REQUIRE(C->Contains(Pizza) == false);
    }
}


/*
while we could not check if one input file equals another (since my function takes user inputs)
in the followuing test, i make an item object, and sample string values (a,b,c)
and i compare if the item object method List_Item() returns the same string 
that the output file is

if you look at my code (Store.cc) my output file for inventory is 100% based
on List_Item() method, so if this method is returing the right strings then,
my output file will be the same
*/
TEST_CASE("Checking if Outputs will be the same ", "[STORE]")
{
    TECH * tv = new TECH("TV,200,3");
    TECH * apple = new TECH("Iphone,999,5");
    FOOD * pizza = new FOOD("Pizza,30,30");


    std::string a = "Tech TV,200,3\n";
    std::string b = "Tech Iphone,999,5\n";
    std::string c = "Food Pizza,30,30\n";
    
    SECTION("Test if the List_Item() function returns the same strig as output file")
    { 

        REQUIRE(tv->List_Item() == a);
        REQUIRE(apple->List_Item() == b);
        REQUIRE(pizza->List_Item() == c);

    }

    SECTION("Test if two diffrent item objects with same string dont match")
    { 

        TECH * appleTech = new TECH("Iphone,999,50");
        FOOD * appleFood = new FOOD("Iphone,999,50");


        b = "Tech Iphone,999,50\n";
        c = "Food Iphone,999,50\n";

        REQUIRE(appleTech->List_Item() == b);
        REQUIRE(appleFood->List_Item() == c);

        REQUIRE(appleTech->List_Item() != c);
        REQUIRE(appleFood->List_Item() != b);


    }
}
