#pragma once
#include <string>

class Task {
private:
  std::string name;
  int priority;
  double estimatedTimeHours;
  std::string department;
  bool done;

public:
  Task() = default;
  Task(
    std::string name,
    int priority,
    double estimatedTimeHours,
    std::string department,
    bool done = false
  );

  const std::string& getName() const;
  int getPriority() const;
  double getEstimatedTimeHours() const;
  const std::string& getDepartment() const;
  bool isDone() const;

  void setDone(bool d);
  void print() const;
};
