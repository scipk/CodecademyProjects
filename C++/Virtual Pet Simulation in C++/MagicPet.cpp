#include "MagicPet.hpp"
#include <iostream>
using namespace std;

void MagicPet::makeSound() {
  cout << getName() << " makes a mystical sound!" << endl;
}

void MagicPet::doTrick() {
  cout << getName() << " performs a magic trick!" << endl;
}

