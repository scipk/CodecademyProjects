#include "RobotControlCenter.hpp"

void RobotControlCenter::logError(const std::string& errorMessage) noexcept {
  std::cout << "[Error] " << errorMessage << std::endl;
}

RobotControlCenter::RobotControlCenter(int capacity) {
  if (capacity < 0) throw RobotException("[Exception] Capacity cannot be negative.");
  std::cout << "Control Center created" << std::endl;
}

void RobotControlCenter::addRobot(Robot* robot) {
  robotCollection.push_back(robot);
}

void RobotControlCenter::executeAllRobotTasks() {
  try {
    for (Robot* robot : robotCollection) {
      robot->performTask();
    }
  } catch (const BatteryLowException& e) {
    logError(e.what());
  } catch (const MechanicalFailureException& e) {
    logError(e.what());
  } catch (const RobotException& e) {
    logError(e.what());
  } catch (...) {
    logError("Unknown exception occurred.");
  }
}
