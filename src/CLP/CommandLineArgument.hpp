/* CommandLineArgument.hpp
 *
 * Author: Mattias Tiger, 2017 
 * * * * * * * * * * * * * * * */

#include <string>
#include <cstring>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <map>
#include <cstdint>

#include "InformativeAssert.hpp"
#include "helper_functions.hpp"
#include "argument_parser.hpp"

#ifndef __COMMAND_LINE_ARGUMENT__
#define __COMMAND_LINE_ARGUMENT__

namespace CLP {

/* --- Declarations --- */
/* -------------------- */

class CommandLineArgument {
  public:

    CommandLineArgument() {}

    CommandLineArgument(std::string shortName, std::string longName, 
			                  std::string description, std::uintptr_t parserIdentifier, 
			                  bool hasValue = true);

    bool isset() const;

    bool hasDefault() const;

    bool hasShortName() const;

    bool hasLongName() const;

    bool hasParameter() const;

    std::string getShortName() const;

    std::string getLongName() const;

    std::string getDescription() const;

    std::uintptr_t getParserIdentifier() const;

    template <class T> 
    T getValue() const;

    void setValue(const char * str);

    template <class T> 
    void setDefaultValue(T value);

    std::string getValueString() const;

    std::string getDefaultValueString() const;

    std::string generateParseErrorMessage(std::string type) const;

  private:
    std::string shortName, longName;
    std::string description;
    std::string value;
    std::string defaultValue;
    std::uintptr_t parserIdentifier;
    bool hasValue;
};


template <class T>
T parse_argument(const CommandLineArgument & argument);

template <class T>
std::uintptr_t argument_parser_identifier();

// TODO: Extend AssertM for lazy evaluation of a message-generating function.
#define ASSERT_ARGUMENT(expression,T,argument)\
AssertM(expression, argument.generateParseErrorMessage(#T));

#define TO_STRING(arg) #arg


/* --- Implementation of template methods --- */
/* ------------------------------------------ */

template <class T> T CommandLineArgument::getValue() const {
  AssertM(isset() || hasDefault(), "Argument '" << getShortName() << "'/'" << getLongName() << "' is not set and has no default value.");
  return parse_argument<T>(*this);
}


template <class T>
void CommandLineArgument::setDefaultValue(T value) {
  defaultValue = serialize(value);
}


/* --- Implementation of template functions --- */
/* -------------------------------------------- */

template <class T>
std::uintptr_t argument_parser_identifier() {
  T (*fn)(const CommandLineArgument & argument) = &argument_parser<T>;
  return (std::uintptr_t)fn;
}

template <class T>
T parse_argument(const CommandLineArgument & argument) {  

  AssertM(argument.isset() || argument.hasDefault(), 
          "Argument '" << argument.getShortName() << "'/'" << 
          argument.getLongName() << "' is not set and has no default value.");
  if(argument.isset()) {
    AssertM(argument.getParserIdentifier() == argument_parser_identifier<T>(),
            "Cannot parse argument to type '" << TO_STRING(T) << "', wrong type.");
    return argument_parser<T>(argument);
  } else {  // argument.hasDefaultValue() == true
    return deserialize<T>(argument.getDefaultValueString());
  }
}

template <class T>
T argument_parser(const CommandLineArgument & argument) {
  const bool USER_IMPLEMENTATION = false;
  AssertM(USER_IMPLEMENTATION, 
          "No argument parameter parser for the parameter type used by argument '" << 
           argument.getShortName() << "'/'" << argument.getLongName() << "' has been declared.");
}

}

#endif
