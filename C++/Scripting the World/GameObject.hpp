#pragma once
#include <string>
#include <ostream>
using namespace std;

class ScriptEngine;
class Position;

class GameObject{
public:
  GameObject(string nme, int hlth, float xpos, float ypos, int frame);
  void move(float dx, float dy);
  void takeDamage(int amount);
  friend class ScriptEngine;
  friend bool operator==(const GameObject& gameObject1, const GameObject& gameObject2);
  friend bool operator==(const Position& pos, const GameObject& obj);
  friend string stringify(const GameObject& obj);
  friend ostream& operator<<(ostream& out, const GameObject& obj);

private:
  string name;
  int health;
  float x;
  float y;
  int animationFrame;
};