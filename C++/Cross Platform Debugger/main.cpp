#include <iostream>
#include "values.hpp"
#include "Logger.hpp"
#include "mode.hpp"
#include "Algorithms.hpp"
using namespace std;

int main() {
  #ifdef DEBUG_MODE
    COMPILE_INFO();
  #endif
  return 0;
}
