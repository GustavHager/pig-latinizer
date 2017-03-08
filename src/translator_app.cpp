#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <future>
#include "PigLatinTranslator.hpp"
#include "InverseTranslator.hpp"
#include "CLP/CLP.hpp"
#include "TranslatorGUI.hpp"

int main(int argc, char** argv){

    // Setup command line argument parser
    CLP::CommandLineParser command;
    command.setProgramDescription("==========\nTRANSLATOR is a translation program allowing ordinary people to become unordinary by providing translation from ordinary languages to unordinary languages. --- WARNING highly potent! ---\n\nTHE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.\n\nUsage: translator [options]");

    command.addArgument("-h", "--help", "Display this help text and exit.",CLP::CommandLineParser::NO_PARAMETER);    
    command.addArgument("-p", "--parallel",
                        "Translate the words in parallel using one thread for each word.",
                        CLP::CommandLineParser::NO_PARAMETER);  
    command.addArgument("-i", "--inverse",
                        "Translate the words from pig-latin to english.",
                        CLP::CommandLineParser::NO_PARAMETER);
    command.addArgument("-f", "--file-input",
                        "Use the file from the provided path as input.");
    command.addArgument("-o", "--file-output",
                        "Write result to specified path.");
    command.addArgument("-g", "--graphical-user-interface",
                        "Start the GUI of the translator.",
                        CLP::CommandLineParser::NO_PARAMETER);
    /*
    command.addArgument<int>("-s", "--space-padding",
                             "Pads each word with spaces at the end so that it is at least NUM characters long.",
                             0);*/

    // Parse command line arguments
    bool success = command.parse(argc,argv);   
    if(!success) {
      std::cout << command.parseErrorsToString() << "\n";
      return 0;
    }    
    if(command.isset("--help")) {
      std::cout << command.helpToString() << "\n";
      return 0;
    }
    
    /*// Example to show how arguments can be used
    if(command.isset("--padding")) {
      std::cout << "Padding is set to: " << command.get<int>("--padding") << "\n";
    } else {
      std::cout << "Padding is set to: " << command.get<int>("--padding") << " (using default value)\n";
    }
    */

    
   
    // Select translator (Pig Latin or Inverse Pig latin)
    std::vector<std::string> words;
    Translator * translator;
    if(command.isset("--inverse")) {
      translator = new InverseTranslator();
    } else {
      translator = new PigLatinTranslator();
    }

    // Start the GUI application
    // Currently overrides all other command line arguments except "-g" and "-i"
    if(command.isset("-g")) {
      TranslatorGUI gui;
      gui.setTranslator(translator);
      gui.run();
      return 0;
    }

    // Read words from input
    std::string word;
    if(command.isset("--file-input")) {
      // Read from file
      std::ifstream inputFile;
      inputFile.open(command.get<std::string>("--file-input"));
      AssertM(inputFile.is_open(), "Could not open file.");
      while( inputFile >> word ) {
        words.push_back(word);
      }
      inputFile.close();
    } else {
      // Read from standard input
      std::string line;
      getline(std::cin, line);
      
      std::istringstream str(line);
          
      while( str >> word ) {
        words.push_back(word);
      }
    }
      
    // Translate all words
    std::vector<std::string> translations;
    translations.reserve(words.size());
    if(command.isset("--parallel")) {
      // Parallel
      std::vector<std::future<std::string> > future_translations;
      for (auto& w : words) {
        future_translations.push_back(std::async([&](std::string word) {return translator->translate(word);}, w));
      }
      for (auto& ft : future_translations) {
        translations.push_back(ft.get());
      }
    } else {
      // Serial
      translations.resize(words.size());
      for(int n = 0; n < words.size(); n++) {
        translations[n] = translator->translate(words[n]);
      }
    }

    // Output the result
    if(!translations.empty()) {
      if(command.isset("--file-output")) {
        // Write to file
        std::ofstream outputFile;
        outputFile.open(command.get<std::string>("--file-output"));
        AssertM(outputFile.is_open(), "Could not open file.");
        for (auto& word : translations) {
          outputFile << word << " ";
        }
        outputFile.close();
      } else {
        // Write to standard output
        for(int n = 0; n < translations.size()-1; n++) {
            std::cout << translations[n] << " ";
        }
        if (!translations.empty()) {
            std::cout << translations.back();
        }
        std::cout << '\n';
      }
    }

    return 0;
}
