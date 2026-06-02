#ifndef ROBOT_CONTROL_CENTER_HPP
#define ROBOT_CONTROL_CENTER_HPP

#include <vector>
#include <iostream>
#include "Robot.hpp"
#include "Exceptions.hpp"

class RobotControlCenter {
  private:
    std::vector<Robot*> robotCollection;
    void logError(const std::string& errorMessage) noexcept;
  public:
    RobotControlCenter(int capacity);
    void addRobot(Robot* robot);
    void executeAllRobotTasks();
};



#endif // ROBOT_CONTROL_CENTER_HPP
