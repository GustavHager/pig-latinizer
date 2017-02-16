#include <string>
#include <iostream>
#include "Translator.hpp"

int main(int argc, char** argv){

    Translator translator;
    std::string input;

    std::cin >> input;

    std::cout << translator.translate(input) << '\n';

    return 0;
}
