#include <iostream>
#include <sstream>
#include "GameObject.hpp"
#include "ScriptEngine.hpp"
#include "Position.hpp"
using namespace std;

string stringify(const GameObject& obj) {
  return obj.name + "#" + to_string(obj.health) + "#" + to_string(obj.x) + "#" + to_string(obj.y) + "#" + to_string(obj.animationFrame);
}

int main() {
  GameObject player1("Hero", 100, 0.0f, 0.0f, 1);
  GameObject player2("Hero", 100, 0.0f, 0.0f, 1);
  Position posCheck(0.0f, 0.0f);

  if (posCheck == player1) {
    cout << "Position matches player1's position." << endl;
  } else {
    cout << "Position does NOT match player1's position." << endl;
  }

  ScriptEngine::teleport(player1, 10.0f, 5.0f);
  ScriptEngine::heal(player1, 25);
  ScriptEngine::advanceAnimation(player1);

  ScriptEngine::teleport(player2, 5.0f, 7.5f);
  ScriptEngine::heal(player2, 20);
  ScriptEngine::advanceAnimation(player2);

  cout << "Stringified player1: " << stringify(player1) << endl;
  cout << player1;

  return 0;
}
