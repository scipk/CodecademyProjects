#ifndef MAINTENANCE_ROBOT_HPP
#define MAINTENANCE_ROBOT_HPP

#include "Robot.hpp"
#include "Exceptions.hpp"
#include <iostream>

class MaintenanceRobot : public Robot {
  private:
    int mechanicalIntegrity;
  public:
    MaintenanceRobot(const std::string& name, int initialIntegrity);
    virtual void performTask() override;
};



#endif // MAINTENANCE_ROBOT_HPP
