#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void bleep(const std::string &word, std::string &text) {
  std::string result;
  result.reserve(text.size());

  for (size_t i = 0; i < text.size();) {
    if (std::isalnum(static_cast<unsigned char>(text[i]))) {
      size_t j = i;
      while (j < text.size() && std::isalnum(static_cast<unsigned char>(text[j]))) {
        j++;
      }

      std::string token = text.substr(i, j - i);
      if (token == word) {
        result.append(token.size(), '*');
      } else {
        result += token;
      }

      i = j;
    } else {
      result += text[i++];
    }
  }

  text = std::move(result);
}

int main() {
  std::string word = "broccoli";
  std::string text = "I'm rolling up my broccoli. I'm rolling up my broccoli.";

  bleep(word, text);
  std::cout << text << std::endl;
}