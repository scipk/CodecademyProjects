#include "Character.hpp"

void Character::attack(){
  cout << "Basic Low Attack" << endl;
}

void Character::displayInfo(){
  cout << "Name: " << name << ", Health: " << health << ", Power: " << power << endl;
}