#include <vector>
#include "Warrior.hpp"
#include "Sorcerer.hpp"

using namespace std;

int main() {
  vector<Character*> characters;
  characters.push_back(new Warrior("Joe", 50, 100));
  characters.push_back(new Warrior("Shmoe", 30, 40));
  characters.push_back(new Sorcerer("Hoe", 20, 200));
  characters.push_back(new Warrior("Roe", 10, 300));
  characters.push_back(new Warrior("Roe", 100, 100));

  for(Character* character : characters){
    character->displayInfo();
    character->attack();
  }

  Character* characterPtr = new Warrior("Anakin", 300, 3000);
  Warrior* warriorPtr = dynamic_cast<Warrior*>(characters[0]);
  if (warriorPtr != nullptr){
    warriorPtr->specialAttack();
  }

  characters.clear();
  delete characterPtr;
  delete warriorPtr;


  

  return 0;
}
