#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "InverseTranslator.hpp"

int main(int argc, char** argv){

    InverseTranslator InvTranslator;
    std::vector<std::string> words;
    
    std::string line;
    getline(std::cin, line);
    
    std::istringstream str(line);
    std::string word;
        
    while( str >> word ) {
      words.push_back(word);
    }
      
    for(int n = 0; n < words.size()-1; n++) {
        std::cout << InvTranslator.translate(words[n]) << " ";
    }

    if (!words.empty()) {
        std::cout << InvTranslator.translate(words.back());
    }
    std::cout << '\n';

    return 0;
}
