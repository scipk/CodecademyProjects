#include <iostream>

int main() {
  // Age of the Dog now
  int dog_age = 50;

  int early_years, later_years, human_years;

  early_years = 21;

  later_years = (dog_age - 2) * 4;

  human_years = early_years + later_years;

  std::cout << "My name is ____! Ruff ruff, I am " << human_years << " years old in human years.";
  
}