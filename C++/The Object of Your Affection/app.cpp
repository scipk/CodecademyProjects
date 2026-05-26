#include <iostream>

#include "profile.hpp"

int main() {

  Profile sam("Sam Drakkilla", 30, "New York", "USA", "he/him");

  sam.add_hobby("Skiing");
  sam.add_hobby("Snowboarding");


  std::cout << sam.view_profile();
}