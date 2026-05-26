#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  cout << "MAGIC 8-BALL:\n";

  srand(time(NULL));
  int answer = rand() % 10;

  switch (answer) {
    case 0:
      cout << "It is certain.\n";
      break;
    case 1:
      cout << "Very doubtful.\n";
      break;
    case 2:
      cout << "Without a doubt.\n";
      break;
    case 3:
      cout << "Yes - definitely.\n";
      break;
    case 4:
      cout << "You may rely on it.\n";
      break;
    case 5:
      cout << "As I see it, yes.\n";
      break;
    case 6:
      cout << "Outlook good.\n";
      break;
    case 7:
      cout << "Cannot predict now.\n";
      break;
    case 8:
      cout << "Concentrate and ask again.\n";
      break;
    case 9:
      cout << "Outlook not so good.\n";
      break;
  }

}