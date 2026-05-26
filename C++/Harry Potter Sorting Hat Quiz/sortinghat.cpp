#include <iostream>
using namespace std;

int main() {

  // The magic starts here
  int gryffindor = 0, hufflepuff = 0, ravenclaw = 0, slytherin = 0;

  int answer1, answer2, answer3, answer4;

  cout << "The Sorting Hat Quiz!\n";

  // Question 1
  cout << "\nQ1) When I'm dead, I want people to remember me as:\n  1) The Good\n  2) The Great\n  3) The Wise\n  4) The Bold\n";
  cin >> answer1;
  switch (answer1) {
    case 1:
      hufflepuff++;
      break;
    case 2:
      slytherin++;
      break;
    case 3:
      ravenclaw++;
      break;
    case 4:
      gryffindor++;
      break;
    default:
      cout << "Invalid Output!\n";
      break;
  }


  // Question 2
  cout << "\nQ2) Dawn or Dusk?\n  1) Dawn\n  2) Dusk\n";
  cin >> answer2;
  switch (answer2) {
    case 1:
      gryffindor++; 
      ravenclaw++;
      break;
    case 2:
      slytherin++; 
      hufflepuff++;
      break;
    default:
      cout << "Invalid Output!\n";
      break;
  }

  // Question 3
  cout << "\nQ3) Which kind of instrument most pleases your ear?\n  1) The violin\n  2) The trumpet\n  3) The piano\n  4) The drum\n";
  cin >> answer3;
  switch (answer3) {
    case 1:
      slytherin++;
      break;
    case 2:
      hufflepuff++;
      break;
    case 3:
      ravenclaw++;
      break;
    case 4:
      gryffindor++;
      break;
    default:
      cout << "Invalid Output!\n";
      break;
  }


  // Question 4
  cout << "\nQ4) Which road tempts you most?\n  1) The wide, sunny grassy lane\n  2) The narrow, dark, lantern-lit alley\n  3) The twisting, leaf-strewn path through woods\n  4) The cobbled street lined (ancient buildings)\n";
  cin >> answer4;
  switch (answer4) {
    case 1:
      hufflepuff++;
      break;
    case 2:
      slytherin++;
      break;
    case 3:
      gryffindor++;
      break;
    case 4:
      ravenclaw++;
      break;
    default:
      cout << "Invalid Output!\n";
      break;
  }
  

  string house;
  int max = 0;
  if (gryffindor > max) {
    max = gryffindor;
    house = "Gryffindor";
  } if (hufflepuff > max) {
    max = hufflepuff;
    house = "Hufflepuff";
  } if (ravenclaw > max) {
    max = ravenclaw;
    house = "Ravenclaw";    
  } if (slytherin > max) {
    max = slytherin;
    house = "Slytherin";
  } 
  std::cout << house << "!\n";

  

}
