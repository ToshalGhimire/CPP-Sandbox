#ifndef TEXT_UI_H
#define TEXT_UI_H

#include <vector>
#include "Store.h"

/*
my TextUI class has a store class inisde of it, and takes in the commandline as agrument

*/
class TextUI {
  public:
    TextUI(char **argv);

    // std::string MainMenu();

    // void RouteChoice(Store s, std::string choice);

    // int ItemMenu(Store s, std::map<int, std::string> items);

    void Start();


  private:
    std::vector<std::string> main_menu_;
    Store * mystore_;
};


#endif  // TEXT_UI_H