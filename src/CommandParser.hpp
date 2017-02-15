#ifndef COMMAND_PARSER_HPP
#define COMMAND_PARSER_HPP

#include <string>

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
