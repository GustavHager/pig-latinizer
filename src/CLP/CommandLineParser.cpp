/* CommandLineParser.cpp
 *
 * Author: Mattias Tiger, 2017 
 * * * * * * * * * * * * * * * */

#include "CommandLineParser.hpp"

namespace CLP {

CommandLineParser::CommandLineParser() {
  programDescription = "<Program description not set!>";
}

void CommandLineParser::setProgramDescription(std::string programDescription) {
  this->programDescription = programDescription;
}

void CommandLineParser::addArgument(std::string argNameShort, std::string argNameLong, std::string description,  Option option) {
  bool hasParameter = option != NO_PARAMETER;
  arguments.push_back(CommandLineArgument(argNameShort, argNameLong, description, argument_parser_identifier<std::string>(), hasParameter));
  int n = arguments.size()-1;
  nameLookUp[argNameShort] = n;
  nameLookUp[argNameLong] = n;
};

bool CommandLineParser::exist(std::string argName) const {
  std::map<std::string,int>::const_iterator argIndex = nameLookUp.find(argName);
  return argIndex != nameLookUp.end();
}

bool CommandLineParser::isset(std::string argName) const {
  std::map<std::string,int>::const_iterator argIndex = nameLookUp.find(argName);
  AssertM(argIndex != nameLookUp.end(), "No argument with name '" << argName << "' exist in this parser.");
  const CommandLineArgument & argument = arguments[argIndex->second];
  return argument.isset();
}

CommandLineArgument & CommandLineParser::getArgument(std::string argName) {
  std::map<std::string,int>::iterator argIndex = nameLookUp.find(argName);
  AssertM(argIndex != nameLookUp.end(), "No argument with name '" << argName << "' exist in this parser.");
  return arguments[argIndex->second];
}

std::string report_error(std::stringstream ss) {
  return ss.str();
}

bool CommandLineParser::parse(int argc, char** argv) {
  bool status = true;
  int n = 1;  // Skip the first argument, it is always the name of the file.
  while(n < argc) {
    if(exist(argv[n])) {
      CommandLineArgument & argument = getArgument(argv[n]);
      if(argument.hasParameter()) {
        if(n+1 < argc && !exist(argv[n+1])) {
          argument.setValue(argv[++n]);
        } else {
          CLP_ERROR("Argument '" << argv[n] << "' expects a parameter but none was provided.");
          status = false;
        }
      } else {
        argument.setValue(" ");
      }
    } else {
      if(std::strcmp(argv[n], "-h") == 0) {
        CLP_ERROR("No help text set.\nList of available arguments:\n" << helpToString());
      } else {
        CLP_ERROR("Argument '" << argv[n] << "' not recognized. Type -h to list all available arguments.");
      }
      status = false;
    }
    n++;
  }
  return status;
}

std::string CommandLineParser::parseErrorsToString() {
  std::stringstream ss;
  ss << errors.size() << " errors during parsing:\n";
  for(int n = 0; n < errors.size(); n++) {
    ss << "  " << n+1 << "): " << errors[n] << "\n";
  }
  return ss.str();
}

std::string CommandLineParser::helpToString() {
  const int Wspace = 2;
  const int Wname = 20;
  const int Wtot = 80;
  std::stringstream ss;
  ss << wrapText(programDescription, Wtot) << "\n";
  for(int n = 0; n < arguments.size(); n++) {
    std::stringstream ss_;
    // Add space
    ss_.fill(' ');
    ss_.width(Wspace);
    ss_ << "";
    // Add argument names
    ss_ << std::fixed << std::left;
    ss_.fill(' ');
    ss_.width(Wname);
    int namesLength;
    if(arguments[n].hasShortName() && arguments[n].hasLongName()) {
      std::stringstream ss__;
      ss__ << arguments[n].getShortName() << ", " << arguments[n].getLongName();
      ss_ << ss__.str();
      namesLength = ss__.str().length();
    } else {
      if(arguments[n].hasShortName()) {
        ss_ << arguments[n].getShortName();
      } else {
        ss_ << arguments[n].getLongName();
      }
    }
    ss << ss_.str();
    // Add description
    if(namesLength > Wspace+Wname) {
      ss << "\n";
      ss << wrapText(arguments[n].getDescription(), Wtot, Wspace+Wname) << "\n";
    } else {
      ss << wrapText(arguments[n].getDescription(), Wtot, Wspace+Wname, true) << "\n";
    }
  }
  return ss.str();
}

};
