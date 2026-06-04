#include "Task.hpp"

#include <utility>
#include <iostream>
#include <iomanip>

Task::Task(std::string name,
       int priority,
       double estimatedTimeHours,
       std::string department,
       bool done)
  : name(std::move(name)),
    priority(priority),
    estimatedTimeHours(estimatedTimeHours),
    department(std::move(department)),
    done(done) {}

const std::string& Task::getName() const { return name; }
int Task::getPriority() const { return priority; }
double Task::getEstimatedTimeHours() const { return estimatedTimeHours; }
const std::string& Task::getDepartment() const { return department; }
bool Task::isDone() const { return done; }

void Task::setDone(bool d) { done = d; }

void Task::print() const {
  std::cout << "Task{name='" << name
        << "', priority=" << priority
        << ", time=" << estimatedTimeHours
        << "h, dept='" << department
        << "', done=" << (done ? "yes" : "no")
        << "}" << std::endl;
}
