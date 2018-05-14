#include "Store.h"

/*

    ctor for the store class, takes in command line argument and does basic parsing of the file, the main parsing is done by the item class 

*/
Store::Store(char **argv){
    

    std::fstream file;

    //Open file then check if it does open correctly
    file.open(argv[1]);
    if (file.fail()){
        std::cerr << "Error opening file!\n";
        exit(1);
    }

    std::string token;
    std::string tempInventory;
    std::string type;
    int lineNO = 1;

    //run through the file
    while(!file.eof()){
        lineNO++;
        file >> token;

        //Record the store name 
        if(store_name_ == "") {
            store_name_ = token;
        }

        //Create a item class then store it in inventory_ vector
        if(token == "Inventory:"){
            while(file >> type >>  tempInventory){
                lineNO++;
                //Parsing tempInventory is done by the item class
                
                //if-else to create the appropriate item class
                if(type == "Tech"){
                   TECH * temp = new TECH(tempInventory); 
                   inventory_.push_back(temp); 
                }else if(type == "Clothes"){
                    CLOTHES * temp = new CLOTHES(tempInventory);
                    inventory_.push_back(temp); 
                }else if(type == "Food"){
                    CLOTHES * temp = new CLOTHES(tempInventory);
                    inventory_.push_back(temp); 
                }else{
                    
                    std::cout << "ERROR < This Item Sub class is not defined >" << std::endl;
                    std::cout << "\tLine " << lineNO << " -- Type: " << type << " - Item: " << tempInventory << std::endl << std::endl;
                }
                

                  

            }
            break;
        }
    }


    file.close();
    
};

/*
    Display the Stores inventory, if bool is set to true, then it also displays numbers 

    @param optional bool pram
    @return void

*/
void Store::DisplayInventory(bool showList){
    
    if (showList){
        int counter = 1;
        std::cout << "\nSTORE INVENTORY:"<< std::endl;
        for(auto a : inventory_){
            std::cout << " (" << counter++ << ") " << a->DisplayItem();
        }
        std::cout << std::endl;

    } else {

        std::cout << "\nSTORE INVENTORY:"<< std::endl;
        for(auto a : inventory_){
            std::cout << a->DisplayItem();
        }
        std::cout << std::endl;

    }
};


/*
    method that adds an item to the cart, asks for user input and then checks to see if its in bounds
    uses the Contain method from cart class to check if the item is already in cart, if it is, it changes the values accordling
    if it is not already in the cart, it makes a new item object then sets its quanity to one, and decrements the inventory

    @param void
    @return void

*/
void Store::AddItemToCart(){
    this->DisplayInventory(true);
    mycart_->DisplayCart();
    int input;
    std::cout << "\n(0 to quit) Please select an item to add: ";
    std::cin >> input; 

    //bound checking
    if(input == 0){
        std::cout << std::endl;
        return;
    }
    if(input > static_cast<int>(inventory_.size()) || input < 0 ){
        std::cout << "\nINDEX ERROR < Try Again > \n" << std::endl;
        this->AddItemToCart();
        return;
    }
    if(inventory_[input-1]->get_quanity() == 0){
        //if item is out of stock
        std::cout << "\nThis Item Is Out Of Stock!\n";
        this->AddItemToCart();
        return;

    }

    //transfuring items from Inventory <=> Cart
    if(mycart_->Contains(inventory_[input-1])){
        //if item is already in Cart
        mycart_->IncAmmout(inventory_[input-1]);
        inventory_[input-1]->Dec();
    }else{
        //else case to create the new item if its not already in Cart
        ItemType a = inventory_[input-1]->get_type();

        if(a == ItemType::Tech){
            TECH * temp = new TECH(inventory_[input-1]->OUT());
            temp->newitem();
            mycart_->Add2Vector(temp);

        }else if(a == ItemType::Clothes){
            CLOTHES * temp = new CLOTHES(inventory_[input-1]->OUT());
            temp->newitem();
            mycart_->Add2Vector(temp);
            
        }else if ( a == ItemType::Food){
            FOOD * temp = new FOOD(inventory_[input-1]->OUT());
            temp->newitem();
            mycart_->Add2Vector(temp);

        }

        inventory_[input-1]->Dec();

        

    }
    //user feedback
    std::cout << "\nYou added one " << inventory_[input-1]->get_name() <<" to your Cart!\n";
    mycart_->DisplayCart();
};


/*
    Method used to remove item from a Cart, it first asks user input for what item, then checks bounds
    after that it calls the RemoveFromVector Cart method to remove that index, then ajustes the stores inventory accordlingly

    @param void
    @return void

*/
void Store::RemoveItemFromCart(){
    std::cout << std::endl;
    mycart_->DisplayCart(true);
    int input;
    std::cout << "\n(0 to quit) Please select an item to remove: ";
    std::cin >> input; 

    //Bound check
    if(input == 0){
        std::cout << std::endl;
        return;
    }
    if(input > static_cast<int>(mycart_->CartSize()) || input < 0 ){
        std::cout << "\nINDEX ERROR < Try Again > \n" << std::endl;
        this->RemoveItemFromCart();
        return;
    }

    //Update Inventory 
    for(auto& a: inventory_){
        if(mycart_->ReturnName(input) == a->get_name()){
            a->Inc();
        }
    }

    //remove from Cart
    mycart_->RemoveFromVector(input);

    

    //user feedback
    std::cout << "\nYou removed " << mycart_->ReturnName(input) << " from your cart!" << std::endl;
    mycart_->DisplayCart(true);

};


/*
    checkout calls the CartPricee method and returns the cost of cart 

    @param none
    @return void
*/
void Store::Checkout(){
    std::cout << "Hello there! Welcome to the checkout.\n" 
              << "Your total today is " << mycart_->CartPrice() << "!" << std::endl;
    
    mycart_->ClearCart();



};


/*
    the leave function makes sure it emptys cart and returns items back to the store if the cart is not already empty

    @param none
    @return void
*/
void Store::leave(){
    //checks if cart is empty
    if(mycart_->IsEmpty()){

        std::cout << "Goodbye!\n" << std::endl;
    }
    else
    {
        //if not empty it puts all items back until cart quanitiy is equal to 0, then clears the cart an

        std::cout << "Goodbye!\nYour Cart items has been returned to the store\n" << std::endl;

        std::vector<Item*> temp = mycart_->get_cart();
        
        for(auto& a : temp){
            for(auto& b : inventory_){

                if(a->get_name() == b->get_name()){
                    while(a->get_quanity() != 0){
                       a->Dec();
                       b->Inc();
                    }
                }

            }
        }

        mycart_->ClearCart();


    }

    //code for rewriting the files
    this->OutputFile();
};


/*

    this function overwrites the store.txt file with the updated inventory list using the List_Item() method
    
    @param none
    @return void
*/

void Store::OutputFile(){
    std::ofstream myfile;
    myfile.open("store.txt", std::ios::trunc);
    
    myfile << store_name_ << "\n" << "\n" <<"Inventory:\n";

    for(auto c : inventory_){
        myfile << c->List_Item();
    }

    myfile.close();
}