#include "Logger.hpp"
#include "values.hpp"
#include "Algorithms.hpp"
using namespace std;

void Algorithms::singleLoop() {
  LOG_LOCATION("Running single loop");
  START_TIMER();
  for (int i = 0; i < 1000; ++i) {
  }
  STOP_TIMER();
}

void Algorithms::doubleLoop() {
  LOG_LOCATION("Running double loop");
  START_TIMER();
  for (int i = 0; i < 1000; ++i) {
    for (int j = 0; j < 1000; ++j) {
    }
  }
  STOP_TIMER();
}

void Algorithms::tripleLoop() {
  LOG_LOCATION("Running triple loop");
  START_TIMER();
  for (int i = 0; i < 1000; ++i) {
    for (int j = 0; j < 1000; ++j) {
      for (int k = 0; k < 1000; ++k) {
      }
    }
  }
  STOP_TIMER();
}
