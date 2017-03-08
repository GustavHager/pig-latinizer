#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <future>
#include "PigLatinTranslator.hpp"
#include "InverseTranslator.hpp"
#include "CLP/CLP.hpp"

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
    

    std::vector<std::string> words;
    Translator * translator;
    if(command.isset("--inverse")) {
      translator = new InverseTranslator();
    } else {
      translator = new PigLatinTranslator();
    }

    // Read words from input
    std::string line;
    getline(std::cin, line);
    
    std::istringstream str(line);
    std::string word;
        
    while( str >> word ) {
      words.push_back(word);
    }

    std::vector<std::string> translations;
    translations.reserve(words.size());
      
    // Translate all words
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
    for(int n = 0; n < words.size()-1; n++) {
        std::cout << translations[n] << " ";
    }
    if (!words.empty()) {
        std::cout << translations.back();
    }
    std::cout << '\n';

    return 0;
}
