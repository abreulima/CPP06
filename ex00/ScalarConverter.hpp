#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

enum Types
{
    _char,
    _int,
    _float,
    _double,
    infOrNaN,
    error
};

class ScalarConverter
{
public:
    static void convert(const std::string& input);

private:

    // OCF
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();
    
    // Types
    static bool isChar(const std::string& input);
    static bool isInt(const std::string& input);
    static bool isFloat(const std::string& input);
    static bool isDouble(const std::string& input);
    static bool isInfOrNaN(const std::string& input);
    static bool isDoubleOrFloat(const std::string& input);
    static bool isFinite(double value);
    static Types getType(const std::string& input);

    // Displays
    static void displayChar(double value, bool nan);
    static void displayInt(double value, bool nan);
    static void displayFloat(double value, bool isInf, bool isNaN, bool isNeg);
    static void displayDouble(double value, bool isInf, bool isNaN, bool isNeg);
};

#endif