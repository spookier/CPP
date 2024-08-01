#include "../incs/ScalarConverter.hpp"

bool check_if_char(const std::string &str)
{
    if (str.length() == 1 && !std::isdigit(str[0]) == true)
		return true;
	else
		return false;
}

void convert_to_char(const std::string &str, double value)
{
    std::cout << "char: ";
    if (check_if_char(str) == true)
	{
        std::cout << "'" << str[0] << "'";
    }
	else if (value >= 32 && value <= 126) 	// printable characters
	{
        std::cout << "'" << static_cast<char>(value) << "'"; // outputs it as a char
    }
	else if (value >= 0 && value <= 31) 	// non-printable characters
	{
        std::cout << "Non displayable";
    }
	else
	{
        std::cout << "Impossible";
    }
    std::cout << std::endl;
}

void convert_to_int(const std::string &str, double value)
{
    std::cout << "int: ";
    if (check_if_char(str) == true)
	{
        std::cout << static_cast<int>(str[0]);
    }
	else if (value >= -2147483648 && value <= 2147483647) // int range
	{
        std::cout << static_cast<int>(value);
    }
	else
	{
        std::cout << "Impossible";
    }
    std::cout << std::endl;
}


void convert_to_float(const std::string &str, double value)
{
	std::cout << "float: ";
    if (check_if_char(str) == true)
	{
        std::cout << static_cast<float>(str[0]);
    }
	else
	{
        std::cout << static_cast<float>(value);
    }
	if (static_cast<float>(value) - static_cast<int>(value) == 0)
		std::cout << ".0";
    std::cout << "f" << std::endl;
}

void convert_to_double(const std::string &str, double value)
{
    std::cout << "double: ";
    if (check_if_char(str))
	{
        std::cout << static_cast<double>(str[0]);
    }
	else
	{
        std::cout << value;
    }
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
	double value = std::atof(str.c_str()); // converts string to double

    convert_to_char(str, value);
    convert_to_int(str, value);
	convert_to_float(str, value);
	convert_to_double(str, value);
}
