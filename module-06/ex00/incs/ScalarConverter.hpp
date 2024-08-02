#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <cstdlib>
#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();

	public:
		static void convert(const std::string &str);
};

#endif