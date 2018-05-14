#include "Item.h"


Item::Item(ItemType n){
	item_type_ = n;
}

/*
	displays individual items from the class

	@param none
	@return string
*/
std::string Item::DisplayItem(){
    //std::cout << name_ << " [$" << price_ << "] (" << quanity_ << ")" << std::endl;
	std::string out = "";
	out +=  name_ + " [$" + std::to_string(price_) + "] (" + std::to_string(quanity_) + ")" + "\n";
	return out;

};

/*
	this output displays the same information as DisplayItem but it is in the format that will be outputed 

	@param none
	@return string
*/
std::string Item::List_Item(){
    std::string out = "";
    out += name_ + "," + std::to_string(price_) + "," + std::to_string(quanity_) + "\n";
    return  out;
};

/*
	the output is just the 3 thing each item has so as an example ("Iphone,200,10") is outputted

	@param none
	@return string
*/
std::string Item::OUT(){
	std::string out = "";
	out +=  name_ + "," + std::to_string(price_) + "," + std::to_string(quanity_) + ")" + "\n";
	return out;

 };

/*
	default discount
	
	@param none
	@return double 1.0
*/
 double Item::get_discount(){return 1.0;};



/* 
-----------------------------------------------------------------------------------------------------------------
	Tech Item sub class 
-----------------------------------------------------------------------------------------------------------------
*/

/*
	ctor Parses the string using getline and stores it into the variables
	parent class gets Tech enum

	@param string
	@return none
*/
TECH::TECH(std::string a) : Item(ItemType::Tech)
{
	original_item_info_ = a;

	std::stringstream ss(a);

	std::string tempName;
	std::string tempCost;
	std::string tempAmmout;

	std::getline(ss, tempName, ',');
	std::getline(ss, tempCost, ',');
	std::getline(ss, tempAmmout, ',');
	
	name_ = tempName; 
	price_ = std::stoi(tempCost);
	quanity_ = std::stoi(tempAmmout);
};


/*
	it is in the format that will be outputed for tech item type

	@param none
	@return string
*/
std::string TECH::List_Item(){
	std::string out = "Tech ";
    out += name_ + "," + std::to_string(price_) + "," + std::to_string(quanity_) + "\n";
    return  out;
};


//discount functions 
double TECH::get_discount(){
	//no discount for tech sadly
	return 1.0;
	
	};

double TECH::Techdiscount(){
	//no discount for tech sadly
	return 1.0;
	
};

/* 
-----------------------------------------------------------------------------------------------------------------
	Food Item sub class 
-----------------------------------------------------------------------------------------------------------------

*/

/*
	ctor Parses the string using getline and stores it into the variables
	parent class gets Food enum

	@param string
	@return none
*/
FOOD::FOOD(std::string a) : Item(ItemType::Food)
{
	original_item_info_ = a;

	std::stringstream ss(a);

	std::string tempName;
	std::string tempCost;
	std::string tempAmmout;

	std::getline(ss, tempName, ',');
	std::getline(ss, tempCost, ',');
	std::getline(ss, tempAmmout, ',');
	
	name_ = tempName; 
	price_ = std::stoi(tempCost);
	quanity_ = std::stoi(tempAmmout);
};

/*
	it is in the format that will be outputed for Food item type

	@param none
	@return string
*/
std::string FOOD::List_Item(){
	std::string out = "Food ";
    out += name_ + "," + std::to_string(price_) + "," + std::to_string(quanity_) + "\n";
    return  out;
};

//discount functions 
double FOOD::get_discount(){
	std::cout << "\nCost is the still the same but you got a free sample of this food!\nYumm\n" << std::endl;
	return 1.0;
};

double FOOD::Fooddiscount(){
	std::cout << "\nCost is the still the same but you got a free sample of this food!\nYumm\n" << std::endl;
	return 1.0;
};

/* 
-----------------------------------------------------------------------------------------------------------------
	CLOTHES Item sub class 
-----------------------------------------------------------------------------------------------------------------

*/

/*
	ctor Parses the string using getline and stores it into the variables
	parent class gets Clothes enum

	@param string
	@return none
*/
CLOTHES::CLOTHES(std::string a) : Item(ItemType::Clothes)
{
	original_item_info_ = a;

	std::stringstream ss(a);

	std::string tempName;
	std::string tempCost;
	std::string tempAmmout;

	std::getline(ss, tempName, ',');
	std::getline(ss, tempCost, ',');
	std::getline(ss, tempAmmout, ',');
	
	name_ = tempName; 
	price_ = std::stoi(tempCost);
	quanity_ = std::stoi(tempAmmout);
};

/*
	it is in the format that will be outputed for Clothes item type

	@param none
	@return string
*/
std::string CLOTHES::List_Item(){
	std::string out = "Clothes ";
    out += name_ + "," + std::to_string(price_) + "," + std::to_string(quanity_) + "\n";
    return  out;
};

//discount functions 
double CLOTHES::get_discount(){
	std::cout <<"\nWOW! " << this->get_name() << " is in sale!\n20%% OFF!\n" << std::endl;
	return 0.8;
	
	};


double CLOTHES::Clothesdiscount(){
	std::cout <<"\nWOW! " << this->get_name() << " is in sale!\n20%% OFF!\n" << std::endl;
	return 0.8;
};