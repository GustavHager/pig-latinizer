#ifndef TRANSLATOR_HPP
#define TRANSLATOR_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Translator {
    public:
        virtual std::string translate(const std::string& text) const = 0;
        virtual std::string getName() const = 0;
};
#endif
