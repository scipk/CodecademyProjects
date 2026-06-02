#include "values.hpp"
#include <iostream>
#include <string>
#include <chrono>
using namespace std;

class Logger {
private:
  static TIME_POINT startTime;

public:
  static void logLocation(const std::string& message,
                           const std::string& file,
                           int line,
                           const std::string& function);

  static void startTimer();
  static void stopTimer(const std::string& function);
  static void printCompileInfo();
};

// Macros for easy usage
#define LOG_LOCATION(msg) Logger::logLocation(msg, __FILE__, __LINE__, __FUNCTION__)
#define START_TIMER() Logger::startTimer()
#define STOP_TIMER() Logger::stopTimer(__FUNCTION__)
#define COMPILE_INFO() Logger::printCompileInfo()