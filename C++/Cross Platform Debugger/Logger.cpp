#include "Logger.hpp"
using namespace std;

TIME_POINT Logger::startTime;

void Logger::logLocation(const std::string& message,
                         const std::string& file,
                         int line,
                         const std::string& function) {
  cout << "[LOG] " << file << ":" << line << "(" << function << ")" << " - " << message << endl;
}

void Logger::startTimer() {
  startTime = NOW;
}

void Logger::stopTimer(const std::string& function) {
  TIME_POINT endTime = NOW;
  cout << "[TIMER] " << function << " - Duration: " << DURATION(startTime, endTime);
}

void Logger::printCompileInfo() {
  cout << "Date: " << __DATE__ << endl;
  cout << "Time: " << __TIME__ << endl;
  
  #ifdef __GNUC__ 
    cout << "Compiler: GCC " << __GNUC__ << "." << __GNUC_MINOR__ << endl;
  #elif defined(__clang_major__)
    cout << "Compiler: Clang " << __clang_major__ << "." << __clang_minor__ << endl;
  #elif defined(_MSC_VER)
    cout << "Compiler: MSVC " << _MSC_VER << endl;
  #else
    #error "This compiler is not supported"
  #endif

  cout << "Platform: " << PLATFORM << endl;
}
