#include <iostream>
using namespace std;

int main() {
  int n = 100; // Task: iterate 1..100 by default

  // Simple FizzBuzz loop for 1..n
  for (int i = 1; i <= n; ++i) {
    if (i % 3 == 0 && i % 5 == 0) {
      cout << "FizzBuzz";
    } else if (i % 3 == 0) {
      cout << "Fizz";
    } else if (i % 5 == 0) {
      cout << "Buzz";
    } else {
      cout << i;
    }
    cout << '\n';
  }
  return 0;
}