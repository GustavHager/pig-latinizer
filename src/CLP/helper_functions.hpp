/* helper_functions.hpp
 *
 * Author: Mattias Tiger, 2017 
 * * * * * * * * * * * * * * * */

#include <string>
#include <cstring>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <sstream>

#ifndef __CLP_HELPER_FUNCTIONS__
#define __CLP_HELPER_FUNCTIONS__

namespace CLP {

/* --- Declaration --- */
/* ------------------- */

#define CLP_ERROR(string) \
{\
  std::stringstream ss;\
  ss << string;\
  errors.push_back(ss.str());\
}

template <class T>
std::string serialize(T value);

template <class T>
T deserialize(std::string str);

std::vector<std::string> split(const std::string & str, char delimiter);

std::string wrapText(const std::string & input, size_t width, size_t indent = 0, bool noIndentFirstRow = false);


/* --- Implementation of template functions --- */
/* -------------------------------------------- */

template <class T>
std::string serialize(T value) {
  int size = sizeof(value);
  std::string str(size,' ');
  memcpy(&str[0], &value, size);
  return str;
}

template <class T>
T deserialize(std::string str) {
  int size = str.size();
  T value;
  memcpy(&value, &str[0], size);
  return value;
}

}

#endif
