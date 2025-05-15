#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	loadDatabase(filename);
}


void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream   file;

	std::string     line;
	std::string     date;
	std::string     str_value;
	float           value;

	
	file.open(filename.c_str());
	if(!file)
		throw std::runtime_error("Error: could not open file");


	std::getline(file, line);       // Skip first line (header)
	while(std::getline(file, line))
	{
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			return ;

		date = line.substr(0, commaPos);
		str_value = line.substr(commaPos + 1);
		
		std::istringstream iss (str_value); // convert string to float
		iss >> value;                       // convert string to float

		btc_database[date] = value;         //add the key+value to map

	}
}


float BitcoinExchange::getExchangeRate(const std::string &date) const
{
	if (btc_database.empty())
	{
		throw std::runtime_error("Error: database is empty");
	}
	

	std::map<std::string, float>::const_iterator it = btc_database.lower_bound(date);

	// Check exact match
	if(it != btc_database.end() && it->first == date)
	{
		//std::cout << date << " => " << it->second << std::endl;
		return (it->second);
	}


	// Check if date earlier than db data
	if (it == btc_database.begin())
	{
		throw std::runtime_error("Error: no earlier date in database.");
	}


	// Go previous date if no exact match and date is valid
	it--;
	//std::cout << it->first << " => " << it->second << std::endl;
	return (it->second);

}

void BitcoinExchange::processExchange(const std::string &userDate, float userValue)
{
	std::cout << userDate << " => " << userValue << " = " << (userValue * getExchangeRate(userDate)) << std::endl;
}