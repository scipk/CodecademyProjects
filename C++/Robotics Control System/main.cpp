#include "RobotControlCenter.hpp"
#include "DeliveryRobot.hpp"
#include "MaintenanceRobot.hpp"

int main() {
    RobotControlCenter controlCenter(5);
  // try {
  //   RobotControlCenter controlCenter(5);
  // } catch (const std::invalid_argument& e) {
  //   std::cout << e.what() << std::endl;
  //   return 0;
  // }

  DeliveryRobot* delivery1 = new DeliveryRobot("Coco", 50);
  DeliveryRobot* delivery2 = new DeliveryRobot("Fry", 10);
  MaintenanceRobot* maintenance1 = new MaintenanceRobot("R2-D2", 80);
  MaintenanceRobot* maintenance2 = new MaintenanceRobot("Chopper", 20);
  
  controlCenter.addRobot(delivery1);
  controlCenter.addRobot(delivery2);
  controlCenter.addRobot(maintenance1);
  controlCenter.addRobot(maintenance2);

  try {
    controlCenter.executeAllRobotTasks();
  } catch (...) {
    std::cout << "Unexpected error: shutting down factory" << std::endl << "Program finished." << std::endl;
    return 0;
  }
  
  return 0;
}