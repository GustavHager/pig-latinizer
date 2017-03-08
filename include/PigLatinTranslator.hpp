#ifndef PIG_LATIN_TRANSLATOR_HPP
#define PIG_LATIN_TRANSLATOR_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Translator.hpp"

class PigLatinTranslator : public Translator {
    public:
        PigLatinTranslator();
        std::string translate(const std::string& text) const;
        std::string getName() const { return "English->Pig-Latin"; }
    private:
        std::string translate_word(const std::string& text) const;
        std::vector<std::string> separate_punctuation(const std::string& text) const;
        bool is_punctuation(char c) const;
        std::string vowels;
        std::string punctuation;
};

std::string to_lower_case(std::string str);
std::string to_upper_case(std::string str);
char to_lower_case(char letter);
char to_upper_case(char letter);
bool is_upper_case(char letter);
bool is_all_upper_case(std::string str);

#endif
