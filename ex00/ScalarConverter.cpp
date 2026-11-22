#include "ScalarConverter.hpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <limits>
#include <cctype>
#include <float.h>

ScalarConverter::ScalarConverter() {};
ScalarConverter::~ScalarConverter() {};
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; };
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }

void ScalarConverter::convert(const std::string& input)
{

    Types type = getType(input);
    
    if (type == error)
    {
        std::cout << "Error: invalid input." << std::endl;
        return ;
    }

    double value;

    bool isInf = isInfOrNaN(input);
    bool isNan = input == "nan" || input == "nanf";
    bool isNeg = !input.empty() && input[0] == '-';

    if (type == _char)
        value = static_cast<unsigned char>(input[0]);
    else if (!isInf)
    {
        std::string n = input;
        if (type == _float)
        {
            n.erase(n.length() - 1);
        }

        value = std::strtod(n.c_str(), NULL);
    }

    std::cout << "char: ";
    displayChar(value, isInf);
    std::cout << std::endl;

    std::cout << "int: ";
    displayInt(value, isInf);
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(1);

    std::cout << "float: ";
    displayFloat(value, isInf, isNan, isNeg);
    std::cout << std::endl;

    std::cout << "double: ";
    displayDouble(value, isInf, isNan, isNeg);
    std::cout << std::endl;

}
bool ScalarConverter::isChar(const std::string& input)
{
    if (input.length() != 1)
        return false;
    
    if (std::isdigit(static_cast<unsigned char>(input[0])))
        return false;

    if (!std::isprint(static_cast<unsigned char>(input[0])))
        return false;

    return true;
}

bool ScalarConverter::isInt(const std::string& input)
{
    size_t i = 0;

    if (input.empty())
        return false;

    if (input[i] == '+' || input[i] == '-')
        i++;

    if (i == input.length())
        return false;

    for (; i < input.length(); i++)
    {
        if (!std::isdigit(static_cast<unsigned char>(input[i])))
            return false;
    }
    return true;
}

bool ScalarConverter::isInfOrNaN(const std::string& input)
{
    if (input == "nan" ||
        input == "nanf" ||
        input == "inf" ||
        input == "+inf" ||
        input == "-inf" ||
        input == "inff" ||
        input == "+inff" ||
        input == "-inff"
    )
        return true;

    return false;
    
}

bool ScalarConverter::isDoubleOrFloat(const std::string& input)
{
    size_t i = 0;
    bool hasDot = false;
    bool hasDigitBeforeDot = false;
    bool hasDigitAfterDot = false;

    if (input.empty())
        return false;

    if (input[i] == '+' || input[i] == '-')
        i++;
    
    // must have digits, a and single dot
    for (; i < input.length(); i++)
    {
        if (std::isdigit(static_cast<unsigned char>(input[i])))
        {
            if (hasDot)
                hasDigitAfterDot = true;
            else
                hasDigitBeforeDot = true;
        }
        else if (input[i] == '.' && !hasDot)
            hasDot = true;
        else
            return false;
    }
    return hasDot && hasDigitAfterDot && hasDigitBeforeDot;
}

bool ScalarConverter::isFloat(const std::string& input)
{
    //float f = X.f;
    // must have .f at least (two characters)
    if (input.length() < 2)
        return false;

    if (input[input.length() - 1] != 'f')
        return false;

    return isDoubleOrFloat(input.substr(0, input.length() - 1));
}

bool ScalarConverter::isDouble(const std::string& input)
{
    return isDoubleOrFloat(input);
}

Types ScalarConverter::getType(const std::string& input)
{
    if (isChar(input))
        return _char;

    if (isInfOrNaN(input))
        return infOrNaN;

    if (isInt(input))
        return _int;
    
    if (isFloat(input))
        return _float;

    if (isDouble(input))
        return _double;

    return error;
}


bool ScalarConverter::isFinite(double value)
{
    // double max
    return value <= DBL_MAX && value >= - DBL_MAX;
}

/*
void ScalarConverter::displayChar(const std::string& input)
{
    char asChar = input.at(0);
    
    std::cout << "char: " << asChar << std::endl;
    std::cout << "int: " << static_cast<int>(asChar) << std::endl;
    std::cout << "float: " << static_cast<float>(asChar) << std::endl;
    std::cout << "double: " << static_cast<double>(asChar) << std::endl;
}
*/

void ScalarConverter::displayInt(double value, bool isInf)
{
    if (isInf)
        std::cout << "impossible";
    else if (!isFinite(value))
        std::cout << "impossible";
    else if (value < INT_MIN || value > INT_MAX)
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(value);
}

void ScalarConverter::displayChar(double value, bool isInf)
{
    if (isInf)
        std::cout << "impossible";
    else if (!isFinite(value))
        std::cout << "impossible";
    else if (value < CHAR_MIN || value > CHAR_MAX)
        std::cout << "impossible";
    else if (!std::isprint(static_cast<unsigned char>(value)))
        std::cout << "Non displayable";
    else
        std::cout << static_cast<char>(value);
}

void ScalarConverter::displayDouble(double value, bool isInf, bool isNaN, bool isNeg)
{
    if (isNaN)
        std::cout << "nan";
    else if (isInf && isNeg)
        std::cout << "-inf";
    else if (isInf)
        std::cout << "inf";
    else if (!isFinite(value))
        std::cout << "impossible";
    else
        std::cout << value;
}


void ScalarConverter::displayFloat(double value, bool isInf, bool isNaN, bool isNeg)
{
    if (isNaN)
        std::cout << "nanf";
    else if (isInf && isNeg)
        std::cout << "-inff";
    else if (isInf)
        std::cout << "inff";
    else if (!isFinite(value))
        std::cout << "impossible";
    else if (value > FLT_MAX || value <- FLT_MAX)
        std::cout << "impossible";
    else
        std::cout << static_cast<float>(value) << "f";
}
