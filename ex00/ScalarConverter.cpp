#include "ScalarConverter.hpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <limits>
#include <cctype>

ScalarConverter::ScalarConverter() {};
ScalarConverter::~ScalarConverter() {};
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; };
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }

void ScalarConverter::convert(const std::string& input)
{

    switch (getType(input))
    {
    case _char:
        displayChar(input);
        break;
    
    default:
        break;
    }

}
bool ScalarConverter::isChar(const std::string& input)
{
    if (input.length() != 1)
        return false;
    
    if (std::isdigit(input[0]))
        return false;

    if (!std::isprint(input[0]))
        return false;

    return true;
}

bool ScalarConverter::isInt(const std::string& input)
{
    size_t i =- 0;

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

Types ScalarConverter::getType(const std::string& input)
{
    if (isChar(input))
        return _char;
    
    return error;
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

void ScalarConverter::displayChar(const std::string& input)
{
    char asChar = input.at(0);

    std::cout << "char: " << asChar << std::endl;
    std::cout << "int: " << static_cast<int>(asChar) << std::endl;
    
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(asChar) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(asChar) << std::endl;
}
