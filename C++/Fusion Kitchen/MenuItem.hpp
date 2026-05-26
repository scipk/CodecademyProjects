#ifndef MENU_ITEM_HPP
#define MENU_ITEM_HPP

#include <string>
using namespace std;

class MenuItem {
  private:
    string name;
    double price;
  public:
    MenuItem(string n, double cost) : name(n), price(cost) {};
    void getInfo();
};

#endif