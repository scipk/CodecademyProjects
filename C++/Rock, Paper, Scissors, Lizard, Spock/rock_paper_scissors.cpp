/* 
  No one cares about this comment...
*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
  
  // Live long and prosper
  srand (time(NULL));
  int computer = rand() % 3 + 1;
  int user = 0;

  cout << "====================\n";
  cout << "rock paper scissors!\n";
  cout << "====================\n";

  cout << "1) ✊\n";
  cout << "2) ✋\n";
  cout << "3) ✌️\n";

  cout << "shoot!\n";

  cin >> user;

  if (user == computer) {
    cout << "Tie!\n";
  } else if ((user == 1 && computer == 3) || (user == 2 && computer == 1) || (user == 3 && computer == 2)) {
    cout << "You win!\n";
  } else if ((user == 3 && computer == 1) || (user == 1 && computer == 2) || (user == 2 && computer == 3)) {
    cout << "You lose!\n";
  } else {
    cout << "Invalid Response!\n";
  }


}
