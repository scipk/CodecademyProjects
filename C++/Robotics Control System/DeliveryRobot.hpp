#ifndef DELIVERY_ROBOT_HPP
#define DELIVERY_ROBOT_HPP

#include "Robot.hpp"
#include "Exceptions.hpp"
#include <iostream>

class DeliveryRobot : public Robot {
  private:
    int batteryLevel;
  public:
    DeliveryRobot(const std::string& name, int initialBatteryLevel);
    virtual void performTask() override;
};



#endif // DELIVERY_ROBOT_HPP
