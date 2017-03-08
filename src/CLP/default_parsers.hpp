/* default_parsers.hpp
 *
 * Author: Mattias Tiger, 2017 
 * * * * * * * * * * * * * * * */

#include "CommandLineArgument.hpp"

#ifndef __CLP_DEFAULT_PARSERS__
#define __CLP_DEFAULT_PARSERS__

namespace CLP {

/* --- Declarations --- */
/* -------------------- */

// Specialization of the string-as-value argument
template<>
std::string argument_parser(const CommandLineArgument & argument) {
  return argument.getValueString();
}

// Specialization of the int-as-value argument
template<>
int argument_parser(const CommandLineArgument & argument) {
  std::string valueStr = argument.getValueString();
  // Check if argument value is an integer
  ASSERT_ARGUMENT(valueStr.size() > 0, int, argument);
  ASSERT_ARGUMENT((valueStr[0] == '-' && valueStr.size() > 1) || (valueStr[0] >= '0' && valueStr[0] <= '9'), int, argument);
  for(int n = 1; n < valueStr.size(); n++) {
     ASSERT_ARGUMENT(valueStr[0] >= '0' && valueStr[0] <= '9', int, argument);
  }
  // Parse argument value
  int value;
  std::stringstream ss;
  ss << valueStr;
  ss >> value;
  return value;
}

//TODO: Add additional default argument parsers

};

#endif
