#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "Translator.hpp"
#include "CommandParser.hpp"

int main(int argc, char** argv){

/*
    CommandLineParser command;
    command.addArgument<int>("-p", "--padding", 
                             "make the translated word at least NUM long by adding spaces as padding at he end of the word", 0);
    command.addArgument("-h", "--help", "display this help text and exit");
    bool success = command.parse(argc,argv);
    
    if( ! success ) {
      std::cout << command.parseErrorsToString() << "\n";
      return 0;
    }
    
    if(command.isset("--help")) {
      std::cout << command.helpToString() << "\n";
      return 0;
    }
    
    if(command.isset<int>("--padding")) {
      std::cout << "Padding is set to: " << command.get<int>("--padding") << "\n";
    }
*/


    Translator translator;
    std::vector<std::string> words;

    // Read words from input
    std::string line;
    getline(std::cin, line);
    
    std::istringstream str(line);
    std::string word;
        
    while( str >> word ) {
      words.push_back(word);
    }
      
    // Translate all words in input
    std::vector<std::string> translations(words.size());
    for(int n = 0; n < words.size(); n++) {
        translations[n] = translator.translate(words[n]);
    }

    // Output the result
    for(int n = 0; n < words.size()-1; n++) {
        std::cout << translations[n] << " ";
    }
    if (!words.empty()) {
        std::cout << translations.back();
    }
    std::cout << '\n';

    return 0;
}
