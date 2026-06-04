#pragma once

#include <vector>
#include <functional>
#include "Task.hpp"

class TaskUtils {
public:
  static std::vector<Task> filter(
    const std::vector<Task>& tasks, 
    const std::function<bool(const Task&)>& predicate);
  static void forEach(std::vector<Task>& tasks, const std::function<void(Task&)>& op);
  static void sort(std::vector<Task>& tasks, const std::function<bool(const Task&, const Task&)>& lessThan);
  static std::vector<Task> apply(const std::vector<Task>& tasks, const std::function<Task(const Task&)>& transformer);
};
