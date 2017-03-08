/* CommandLineArgument.cpp
 *
 * Author: Mattias Tiger, 2017 
 * * * * * * * * * * * * * * * */

#include "CommandLineArgument.hpp"

namespace CLP {

CommandLineArgument::CommandLineArgument(std::string shortName, std::string longName, 
                                         std::string description, size_t parserIdentifier, 
                                         bool hasValue) {
  this->shortName = shortName;
  this->longName = longName;
  this->description = description;
  this->parserIdentifier = parserIdentifier;
  this->hasValue = hasValue;
}

bool CommandLineArgument::isset() const { 
  return !value.empty();
}

bool CommandLineArgument::hasDefault() const { 
  return !defaultValue.empty();
}

std::string CommandLineArgument::getShortName() const { 
  return shortName;
}

std::string CommandLineArgument::getLongName() const { 
  return longName;
}

std::string CommandLineArgument::getDescription() const { 
  return description;

}
int CommandLineArgument::getParserIdentifier() const {
  return parserIdentifier;
}

std::string CommandLineArgument::getValueString() const {
  return value;
}

std::string CommandLineArgument::getDefaultValueString() const {
  return defaultValue;
}

bool CommandLineArgument::hasParameter() const {
  return hasValue;
}

bool CommandLineArgument::hasShortName() const {
  return !shortName.empty();
}

bool CommandLineArgument::hasLongName() const {
  return !longName.empty();
}

void CommandLineArgument::setValue(const char * str) {
  value = std::string(str);
}

std::string CommandLineArgument::generateParseErrorMessage(std::string type) const {
  std::stringstream ss;
  ss << "Argument '" << getShortName() << "'/'" << getLongName() << "' with value '" 
     << value << "' could not be parsed for type '" << type << "'.";
  return ss.str();
}

}

