#ifndef INVERSE_TRANSLATOR_HPP
#define INVERSE_TRANSLATOR_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Translator.hpp"
#include "PigLatinTranslator.hpp"

class InverseTranslator : public Translator {
    public:
        InverseTranslator();
        std::string translate(const std::string& text) const;
        std::string getName() const { return "Pig-Latin->English"; }
    private:
        std::string vowels;
};

bool is_punct_mark_end(std::string str);
bool is_last_2_ay(std::string str);
bool is_last_3_way(std::string str);

#endif
