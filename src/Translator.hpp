#ifndef TRANSLATOR_HPP
#define TRANSLATOR_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Translator{
    public:
        Translator();
        std::string translate(const std::string& text) const;
    private:
        std::string vowels;
};

std::string to_lower_case(std::string str);
std::string to_upper_case(std::string str);
char to_lower_case(char letter);
char to_upper_case(char letter);
bool is_upper_case(char letter);
bool is_all_upper_case(std::string str);

/*
template<>
int argument_parser(const CLP::CommandLineArgument & argument) {
  std::string valueStr = argument.getValueString();
  // Check if argument value is an integer
  ASSERT_ARGUMENT(valueStr.size() > 0, int, argument);
  ASSERT_ARGUMENT((valueStr[0] == '-' && valueStr.size() > 1) || (valueStr[0] >= '0' && valueStr[0] <= '9'), int, argument);
  for(int n = 1; n < valueStr.size(); n++) {
     ASSERT_ARGUMENT(valueStr[0] >= '0' && valueStr[0] <= '9', int, argument);
  }
  // Parse argument value
  int value;
  std::stringstream ss;
  ss << valueStr;
  ss >> value;
  return value;
}*/

#endif
