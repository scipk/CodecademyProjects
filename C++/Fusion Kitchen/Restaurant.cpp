#include "Restaurant.hpp"
#include <iostream>

void Restaurant::displayInfo(){
  cout << name << endl;
  cout << address << endl;
}

void Restaurant::describeCuisine(){
  cout << "This restaurant serves various types of cuisines." << endl;
}

void Restaurant::addMenuItem(MenuItem item){
  menu.push_back(item);
}

void Restaurant::displayMenu(){
  cout << name << "'s Menu:" << endl;
  for (int i = 0; i < menu.size(); i++){
    menu[i].getInfo();
  }
}