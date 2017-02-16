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

#endif
