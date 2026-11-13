#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

enum Types
{
    _char,
    _int,
    _float,
    _double,
    _infinity,
    error
};

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    static void convert(const std::string& input);
private:

    // Types
    static bool isChar(const std::string& input);
    static bool isInt(const std::string& input);
    static bool isFloat(const std::string& input);
    static bool isDouble(const std::string& input);
    static bool isChar(const std::string& input);
    static bool isInfOrNaN(const std::string& input);
    static Types getType(const std::string& input);


    // Displays
    static void displayChar(const std::string& input);

};

#endif