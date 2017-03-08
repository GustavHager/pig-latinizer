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

#include "InformativeAssert.hpp"
#include "helper_functions.hpp"

#ifndef __ARGUMENT_PARSER____
#define __ARGUMENT_PARSER__

namespace CLP {

/* --- Declarations --- */
/* -------------------- */

class CommandLineArgument;

template <class T>
T argument_parser(const CommandLineArgument & argument);

};

#endif
