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

#endif
