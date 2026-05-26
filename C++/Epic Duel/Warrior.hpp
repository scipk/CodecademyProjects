#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include "Character.hpp"

class Warrior : public Character {
  public:
    Warrior(string n, int hp, int pwr) : Character(n, hp, pwr) {};
    void attack() override;
    void specialAttack();
};

#endif 
