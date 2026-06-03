#include "GameObject.hpp"
#include "Position.hpp"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& out, const GameObject& obj) {
  out << "GameObject[name=" << obj.name
      << ", health=" << obj.health
      << ", pos=(" << obj.x << "," << obj.y << ")"
      << ", animationFrame=" << obj.animationFrame << "]";
  return out;
}

GameObject::GameObject(string nme, int hlth, float xpos, float ypos, int frame) : name(nme), health(hlth), x(xpos), y(ypos), animationFrame(frame){}

void GameObject::move(float dx, float dy) {
  x += dx;
  y += dy;
}

void GameObject::takeDamage(int amount) {
  health -= amount;
  cout << name << " took " << amount << " damage. Health now: " << health << endl;
}

bool operator==(const GameObject& gameObject1, const GameObject& gameObject2) {
  return (gameObject1.x == gameObject2.x) && (gameObject1.y == gameObject2.y);
}

bool operator==(const Position& pos, const GameObject& obj) {
  return (pos.x == obj.x) && (pos.y == obj.y);
}