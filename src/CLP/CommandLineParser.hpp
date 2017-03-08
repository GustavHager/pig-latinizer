/* CommandLineParser.hpp
 *
 * Author: Mattias Tiger, 2017 
 * * * * * * * * * * * * * * * */

#include "CommandLineArgument.hpp"

#ifndef __COMMAND_LINE_PARSER__
#define __COMMAND_LINE_PARSER__

namespace CLP {

/* --- Declarations --- */
/* -------------------- */

class CommandLineParser {
  public:

    enum Option {
      NONE = 0,
      NO_PARAMETER
    };

  public:

    CommandLineParser();

    void setProgramDescription(std::string programDescription);

    template <class T> 
    void addArgument(std::string argNameShort, std::string argNameLong, 
                     std::string description, T defaultValue, Option option = NONE);

    void addArgument(std::string argNameShort, std::string argNameLong, 
                     std::string description, Option option = NONE);

    bool parse(int argc, char** argv);

    bool exist(std::string argName) const;

    bool isset(std::string argName) const;

    template <class T> 
    T get(std::string argName) const;
    
    std::string helpToString();

    std::string parseErrorsToString();

  private:
    std::string programDescription;
    std::vector<std::string> errors;
    std::vector<CommandLineArgument> arguments;
    std::map<std::string,int> nameLookUp;

    CommandLineArgument & getArgument(std::string argName);
};


/* --- Implementation of template methods --- */
/* ------------------------------------------ */

template <class T> 
void CommandLineParser::addArgument(std::string argNameShort, std::string argNameLong, 
                                    std::string description, T defaultValue, Option option) {
  bool hasParameter = option != NO_PARAMETER;
  arguments.push_back(CommandLineArgument(argNameShort, argNameLong, description, 
                                          (size_t)&argument_parser<T>, hasParameter));
  int n = arguments.size()-1;
  nameLookUp[argNameShort] = n;
  nameLookUp[argNameLong] = n;
  arguments.back().setDefaultValue<T>(defaultValue);
};

template <class T> 
T CommandLineParser::get(std::string argName) const {
  std::map<std::string,int>::const_iterator argIndex = nameLookUp.find(argName);
  AssertM(argIndex != nameLookUp.end(), "No argument with name '" << argName << "' exist in this parser.");
  const CommandLineArgument & argument = arguments[argIndex->second];
  AssertM(argument.isset() || argument.hasDefault(), "Argument '" << argName << 
                                                     "' is not set and has no default value.");
  return argument.getValue<T>();
}

}

#endif
