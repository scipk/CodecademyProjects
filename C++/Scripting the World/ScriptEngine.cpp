#include "ScriptEngine.hpp"
#include "GameObject.hpp"
#include <iostream>
using namespace std;

void ScriptEngine::teleport(GameObject& obj, float newX, float newY) {
  obj.x = newX;
  obj.y = newY;
  cout << "[ScriptEngine] Teleported " << obj.name << " to (" << newX << ", " << newY << ")" << endl;
}

void ScriptEngine::heal(GameObject& obj, int amount) {
  obj.health += amount;
  cout << "[ScriptEngine] Healed by " << amount << ". Health now: " << obj.health << endl;
}

void ScriptEngine::advanceAnimation(GameObject& obj) {
  obj.animationFrame++;
  cout << "[ScriptEngine] Animation frame advanced to: " << obj.animationFrame << endl;
}
