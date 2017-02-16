#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "Translator.hpp"

int main(int argc, char** argv){

    Translator translator;
    std::vector<std::string> words;
    
    std::string line;
    getline(std::cin, line);
    
    std::istringstream str(line);
    std::string word;
    
    while( str >> line ) {
      words.push_back(word);
    }
      
    for(int n = 0; n < words.size()-1; n++) {
        std::cout << translator.translate(words[n]) << " ";
    }
    if (!words.empty()) {
        std::cout << translator.translate(words.back());
    }
    std::cout << '\n';

    return 0;
}
