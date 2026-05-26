#ifndef SORCERER_HPP
#define SORCERER_HPP

#include "Character.hpp"

class Sorcerer : public Character {
  public:
    Sorcerer(string n, int hp, int pwr) : Character(n, hp, pwr) {};
    void attack() override;
};


#endif 
