#include "Pet.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "MagicPet.hpp"
#include <iostream>
#include <vector>
#include <memory> // for smart pointers
using namespace std;

int main() {
  Dog myDog;
  Cat myCat;
  MagicPet myMagicPet;

  myDog.setName("Churro");
  myDog.setAge(3);
  myCat.setName("Chaparito");
  myCat.setAge(4);
  myMagicPet.setName("Charizard");
  myMagicPet.setAge(5);

  vector<Pet*> pets;

  pets.push_back(&myDog);
  pets.push_back(&myCat);
  pets.push_back(&myMagicPet);

  for (Pet* pet : pets) {
    pet->makeSound();

    MagicPet* magicPet = dynamic_cast<MagicPet*>(pet);
    if (magicPet) {
      magicPet->doTrick();
    }
  }

  pets.clear();



  return 0;
}
