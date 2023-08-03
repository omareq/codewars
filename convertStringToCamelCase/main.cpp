#include <string>
#include <cctype>
#include <iostream>

std::string to_camel_case(std::string text) {
  std::string answer;
  for(int i = 0; i < text.length(); i++) {
    if(text[i] == '-' || text[i] == '_') {
      text[i + 1] = std::toupper(text[i + 1]);
      continue;
    }
    answer.push_back(text[i]);
  }
  return answer;
}

int main(int argc, char** argv) {
  std::string answer = to_camel_case("the-stealth-warrior");
  std::cout << answer << "\n";
  answer = to_camel_case("The_stealth_warrior");
  std::cout << answer << "\n";
  answer = to_camel_case("The_stealth-warrior");
  std::cout << answer << "\n";
}