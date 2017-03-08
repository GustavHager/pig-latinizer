/* helper_functions.cpp
 *
 * Author: Mattias Tiger, 2017 
 * * * * * * * * * * * * * * * */

#include "helper_functions.hpp"

namespace CLP {

std::vector<std::string> split(const std::string & str, char delimiter) {
  std::vector<std::string> result;
  std::stringstream ss(str);
  std::string row;
  while(getline(ss, row, delimiter)) {
    result.push_back(row);
  }
  return result;
}

std::string wrapText(const std::string & input, size_t width, size_t indent, bool noIndentFirstRow)
{ 
  std::stringstream out;

  if(!noIndentFirstRow) {
    out << std::string(indent, ' '); 
  }

  // Make sure that line breaks (\n) are used
  std::vector<std::string> rows = split(input, '\n');
  for(int n = 0; n < rows.size(); n++) {
    std::stringstream in(rows[n]);
    size_t current = indent;
    std::string word;

    while (in >> word) {
        if (current + word.size() > width) {
            out << "\n" << std::string(indent, ' ');
            current = indent;
        }
        out << word << ' ';
        current += word.size() + 1;
    }
    if(n+1 < rows.size()) {
      out << "\n";
    }
  }
  return out.str();
}

};
