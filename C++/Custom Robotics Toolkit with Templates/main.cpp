#include "functions.hpp"
#include "DataHolder.hpp"

using namespace std;

void runToolkitDemo() {
  std::string part1 = "chassis";
  std::string part2 = "engine";
  swapValues(part1, part2);
  cout << "Part 1: " << part1 << endl;
  cout << "Part 2: " << part2 << endl;

  DataHolder specialNumber(2.71, 1.618, 9.8);
  cout << specialNumber.getValue() << endl;

  DataHolder<std::string> robotName("Codey the Robot");
  cout << robotName.getValue() << endl;
}

int main() {
  cout << midpoint(10, 20) << endl;
  cout << midpoint(2.71, 3.14) << endl;

  int firstNumber = 5; 
  int secondNumber = 10;
swapValues(firstNumber, secondNumber);
  cout << "First number: " << firstNumber << endl;
  cout << "Second number: " << secondNumber << endl;
  
  string greeting = "hello";
  string planet = "world";
  swapValues(greeting, planet);
  cout << "Greeting: " << greeting << endl;
  cout << "Planet: " << planet << endl;

  DataHolder testNumber(42, 0, 100);
  cout << testNumber.getValue() << endl;
  testNumber.setValue(75);
  testNumber.setValue(150);

  DataHolder<std::string> testString("robotics lab");
  cout << testString.getValue() << endl;

  runToolkitDemo();
}
