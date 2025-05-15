#ifndef PARSE_INPUT_HPP
#define PARSE_INPUT_HPP

#include "BitcoinExchange.hpp"

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <limits>

class ParseInput
{
	private:
		std::string	date_for_btc;
		float		value_for_btc;

		ParseInput();
		ParseInput(const ParseInput &other);
		ParseInput &operator=(const ParseInput &other);
	
	public:
		ParseInput(char *filename, BitcoinExchange &btc);

		const std::string &getDate() const;
		float getValue() const;

		bool verifyLine(std::string &line);

		bool isValidDate(const std::string &date);
		bool isValidValue(const std::string &valueStr, float &parsedValue);
};


#endif