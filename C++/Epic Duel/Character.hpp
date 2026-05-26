#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>

using namespace std;

class Character{
  protected:
    string name;
    int health;
    int power;
  public:
    Character(string n, int hp, int pwr) : name(n), health(hp), power(pwr) {};
    virtual void attack();
    virtual void displayInfo();
};

#endif 