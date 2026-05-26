#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include <string>
#include <vector>
#include "MenuItem.hpp"
using namespace std;

class Restaurant {
  private:
    string name;
    string address;
  protected:
    vector<MenuItem> menu;
  public:
    Restaurant(string n, string addr) : name(n), address(addr) {};
    void displayInfo();
    void describeCuisine();

    void addMenuItem(MenuItem item);
    void displayMenu();
};

#endif
