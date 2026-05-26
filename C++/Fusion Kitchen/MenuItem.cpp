#include "MenuItem.hpp"
#include <iostream>

void MenuItem::getInfo(){
  cout << name << " - $" << price << endl;
}