#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

  // Whale, whale, whale.
  // What have we got here?
  string phrase = "turpentine and turtles";
  vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

  string result;

  for (int i = 0; i < phrase.size(); i++) {
    for (int j = 0; j < vowels.size(); j++) {
      if (phrase[i] == vowels[j]) {
        result.push_back(vowels[j]);
        
        if ((phrase[i] == 'e') || (phrase[i] == 'u')) {
          result.push_back(vowels[j]);
        }
      }
    }
  }

  cout << result << "\n";

}
