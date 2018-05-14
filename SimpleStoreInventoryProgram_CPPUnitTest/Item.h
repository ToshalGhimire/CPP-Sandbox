#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

enum class ItemType {Tech,Clothes,Food};

/*
    Item class and subclass are defined here and in Item.cc
    had to use all caps for subclass beacuse the enum already was defined already


*/
class Item {

    public:
        Item(ItemType t);
          // Copy constructor
        //Item(const Item &p2) {name_ = p2.name_; price_ = p2.price_; quanity_ =  p2.quanity_;}
        void newitem(){quanity_ = 1;}

        ItemType get_type(){return item_type_;}
        std::string get_name(){return name_;}
        int get_price(){return price_;}
        int get_quanity(){return quanity_;}

        
        std::string OUT();

        void Inc(){quanity_++;}
        void Dec(){quanity_--;}

        virtual double get_discount();
        virtual std::string List_Item();
        std::string DisplayItem();

    protected:
        std::string name_;
        int price_;
        int quanity_;

    private:
        ItemType item_type_;


};

//Tech item subclass
class TECH : public Item
{
    public:
        TECH(std::string s);
        std::string List_Item();
        double get_discount();
        double Techdiscount();

    private:
        std::string original_item_info_;

};

//Food item subclass
class FOOD : public Item
{
    public:
        FOOD(std::string s);
        std::string List_Item();
        double get_discount();
        double Fooddiscount();

    private:
        std::string original_item_info_;

};

//Clothes item subclass
class CLOTHES : public Item
{
    public:
        CLOTHES(std::string s);
        std::string List_Item();
        double get_discount();
        double Clothesdiscount();

    private:
        std::string original_item_info_;

};





#endif //ITEM_H