#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <string>


class BitcoinExchange
{
	private:
		std::map<std::string, float> btc_database;
		
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

	
	public:
		BitcoinExchange(const std::string &filename);

		void loadDatabase(const std::string &filename);
		float getExchangeRate(const std::string &date) const;

		void processExchange(const std::string &date, float value);
};


#endif