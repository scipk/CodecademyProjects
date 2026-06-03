#pragma once

class GameObject;

class ScriptEngine {
public:
  static void teleport(GameObject& obj, float newX, float newY);
  static void heal(GameObject& obj, int amount);
  static void advanceAnimation(GameObject& obj);
};