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
		
	
	public:
		BitcoinExchange(const std::string &filename);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		std::map<std::string,float> getMap() const;

		void loadDatabase(const std::string &filename);
		float getExchangeRate(const std::string &date) const;

		void processExchange(const std::string &date, float value);
};


#endif