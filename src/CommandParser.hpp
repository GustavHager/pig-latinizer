#ifndef COMMAND_PARSER_HPP
#define COMMAND_PARSER_HPP

#include <string>

/*
namespace ARG {
  enum ArgType {
    NONE = 0,
    BOOL,     // bool: {0,1}
    NUMBER,   // int|float
    INT,      // int
    POS_INT,  // 0,1,2,...
    NEG_INT,  // -1,-2,...
    FLOAT,    // float
    CHAR,     // char
    STRING,   // std::string: "A sentence in a string"                (example)
    WORD,     // std::string: "pig"                                   (example)
    JSON      // std::string: "{key0: {key1: value1}, key2: value1}"  (example)
  };
}

class CommandLineParser {
  public:
    template <class T> 
      void addArgument(std::string argNameShort, std::string argNameLong, std::string description, T defaultValue) { };
      void addArgument(std::string argNameShort, std::string argNameLong, std::string description) { };
    bool parse(int argc, char** argv);
    template <class T> bool isset(std::string argName) { return false; };
    bool isset(std::string argName) { return false; };
    bool get(std::string argName) { return false; };
    template <class T> bool get(std::string argName) { return false; };
    
    std::string helpToString();
    std::string parseErrorsToString();
};
*/

template <typename T>
class CommandLineParameter{
    public:
        CommandLineParameter(const std::string name, const bool required);
    private:
        const std::string parameter_name;
        const bool required;
        T parameter_value;
};

#endif
