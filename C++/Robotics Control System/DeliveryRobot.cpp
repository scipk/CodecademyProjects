#include "DeliveryRobot.hpp"

DeliveryRobot::DeliveryRobot(const std::string& name, int initialBatteryLevel) : Robot(name), batteryLevel(initialBatteryLevel) {}

void DeliveryRobot::performTask() {
  if (batteryLevel < 20) throw BatteryLowException("Battery is Low!");
  std::cout << "DeliveryRobot is delivering" << std::endl;
  batteryLevel -= 10;
  std::cout << "Delivery done" << std::endl;
}
