#ifndef TRANSLATOR_HPP
#define TRANSLATOR_HPP

#include <string>

class Translator{
    public:
        Translator();
        std::string translate(const std::string& text) const;
    private:
};

#endif
