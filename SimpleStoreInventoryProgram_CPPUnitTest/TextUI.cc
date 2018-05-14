#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip> // setprecision
#include <sstream> // stringstream

#include "Store.h"
#include "TextUI.h"



TextUI::TextUI(char **argv) {
  // set up the main menu

  mystore_ = new Store(argv);

  main_menu_.push_back("Display inventory");
  main_menu_.push_back("Add item to cart");
  main_menu_.push_back("Remove item from cart");
  main_menu_.push_back("Checkout");
  main_menu_.push_back("Leave");
}

/*
  The reason I changed the textui was beacuse the origianl one seemd too confusing.The most confusing part was the way it used a store and map as arguments I didnt quite understand.
  so i tried to make a simple textUI by using switch statments and just function calls based on the user input

  after doing this, i realized that this was a terrible idea, i could not run the test properaly beacuse of this, it seemded simple at first but i realized that my way was poor design
  
  in future assignemnts i will not use this, i have learned my lession

*/

void TextUI::Start(){
  int input;

  std::cout << "===========================" << std::endl;
  std::cout << "Welcome to " << mystore_->get_StoreName()<< "!" << std::endl;
  std::cout << "===========================" << std::endl;

  while (true){
    
    int counter = 1;
    
    std::cout<< "MAIN MENU" << std::endl;
    for(auto i : main_menu_){
    
      std::cout <<counter++ << ") "<< i << std::endl;
    }

    do {
      std::cout << " > ";
      std::cin >> input;

    }while(input < 0 || input > 5);
    
   // system("clear");

    switch(input){
      case 1: 
        mystore_->DisplayInventory();
        break;
      case 2: 
        std::cout <<"\nNeed to add item to cart\n"<< std::endl;
        mystore_->AddItemToCart();
        
        break;
      case 3: 
        std::cout <<"\nNeed to remove item from cart\n"<< std::endl;
        mystore_->RemoveItemFromCart();
    
        break;
      case 4: 
        std::cout <<"\nNeed to checkout\n"<< std::endl;
        mystore_->Checkout();
        break;
      case 5: 
        std::cout <<"\nNeed to leave\n"<< std::endl;
        mystore_->leave();
        return;
        break;
      default:
          std::cout <<"\nDefault case\n"<< std::endl;
        break;
      
    }
   
  } 
 
}




// std::string TextUI::MainMenu(){};
// void TextUI::RouteChoice(Store s, std::string choice){};
// int TextUI::ItemMenu(Store s, std::map<int, std::string> items){};

/*
std::string TextUI::MainMenu() {
  int choice = -1;
  while (choice < 0 || choice >= main_menu_.size()) {
    // display the main menu
    for (int i = 0; i < main_menu_.size(); i++) {
      std::cout << std::to_string(i) << ": " << main_menu_[i] << std::endl;
    }
    std::string str_choice;
    std::cin >> str_choice;
    try {
      choice = std::stoi(str_choice);
    } catch (const std::invalid_argument& ia) {
      std::cout << "Enter a number" << std::endl;
    }
  }
  return main_menu_[choice];
}


int TextUI::ItemMenu(Store s, std::map<int, std::string> items) {
  int choice = -1;
  while (items.find(choice) == items.end() && choice != 0) {
    // display the main menu
    std::cout << "0: Back to main menu" << std::endl;
    std::map<int, std::string>::iterator it = items.begin();
    while(it != items.end()) {
      std::cout << std::to_string(it->first) << ": " << it->second << std::endl;
      it++;
    }
    std::string str_choice;
    std::cin >> str_choice;
    try {
      choice = std::stoi(str_choice);
    } catch (const std::invalid_argument& ia) {
      std::cout << "Enter a number" << std::endl;
    }
    std::cout << std::endl;
  }
  return choice;
}

void TextUI::RouteChoice(Store s, std::string choice) {
  if (choice == "Display inventory") {
    std::cout << "Store inventory" << std::endl;
    std::cout << s.DisplayInventory() << std::endl;
  } else if (choice == "Add item to cart") {
    std::map<int, std::string> items = s.Items();
    if (items.size() > 0) {
      std::cout << "Adding item to cart" << std::endl;
      int choice = this->ItemMenu(s, items);
      if (choice != 0) {
        s.AddItemToCart(choice);
        std::cout << "Cart: " << std::endl << s.DisplayCart() << std::endl;
        std::cout << "Inventory: " << std::endl << s.DisplayInventory() << std::endl;
      }
    } else {
      std::cout << "There are no items left in this store." << std::endl;
    }
  } else if (choice == "Remove item from cart") {
    std::map<int, std::string> items = s.CartItems();
    if (items.size() > 0) {
      std::cout << "Removing item from cart" << std::endl;
      int choice = this->ItemMenu(s, items);
      if (choice != 0) {
        s.RemoveItemFromCart(choice);
        std::cout << "Cart: " << std::endl << s.DisplayCart() << std::endl;
        std::cout << "Inventory: " << std::endl << s.DisplayInventory() << std::endl;
      }
    } else {
      std::cout << "There are no items in your cart." << std::endl;
    }
  } else if (choice == "Checkout") {
    double total = s.Checkout();
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << total;
    std::string s = stream.str();
    std::cout << "Your total is: " << s << std::endl;
  } else {
    // Leave
    s.ClearCart();
    std::cout << "Goodbye! The items in your cart have been returned to the store." << std::endl;
  }
}

*/