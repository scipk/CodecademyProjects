#include <iostream>
#include <vector>

using namespace std;

// Text adventure based on the Elder Scrolls.
int main() {
  // Beginning
  cout << "=====================\nAn Elder Scrolls Adventure\n=====================\n";
  

  int ending = 0;
  

  // Character Selection
  int race = 0;

  cout << "Races:\n";
  cout << "0 - Imperial,  1 - Breton,   2 - Nord\n";
  cout << "3 - Redguard,  4 - Argonian, 5 - Khajiit\n";
  cout << "6 - Orc,       7 - Dunmer,   8 - Bosmer\n";
  cout << "9 - Altmer\n";
  cout << "Pick a race: ";
  cin >> race;

  switch (race) {
    case 0:
      cout << "\nYou chose Imperial!";
      ending += 2;
      break;
    case 1:
      cout << "\nYou chose Breton!";
      ending += 1;
      break;
    case 2:
      cout << "\nYou chose Nord!";
      ending += 2;
      break;
    case 3:
      cout << "\nYou chose Redguard!";
      ending += 1;
      break;
    case 4:
      cout << "\nYou chose Argonian!";
      ending += 5;
      break;
    case 5:
      cout << "\nYou chose Khajiit!";
      ending += 5;
      break;
    case 6:
      cout << "\nYou chose Orc!";
      ending += 2;
      break;
    case 7:
      cout << "\nYou chose Dunmer!";
      ending += 1;
      break;
    case 8:
      cout << "\nYou chose Bosmer!";
      ending += 1;
      break;
    case 9:
      cout << "\nYou chose Altmer!";
      ending += 5;
      break;
  }

  // Ending
  if (ending == 2) {
    cout << "\nElder Scrolls VI will release in 2027.\n";
  } else if (ending == 1) {
    cout << "\nElder Scrolls VI will release in 2026.\n";
  } else {
    cout << "\nElder Scrolls VI will never release.\n";
  }
  

  return 0;
}