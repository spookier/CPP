#include "ParseInput.hpp"

ParseInput::ParseInput(char *filename, BitcoinExchange &btc)
{
    std::ifstream   file;
    std::string     line;


	file.open(filename);
	if(!file)
		throw std::runtime_error("Error: could not open user file");

    
    std::getline(file, line);           // skip header
    while(std::getline(file, line))
	{
        if(verifyLine(line) == false)
        {
            continue ;
        }
        btc.processExchange(getDate(), getValue()); // process exchange for each line
	}
}


bool ParseInput::verifyLine(std::string &line)
{
    size_t      pos;
    float       parsedValue;
    std::string date;
    std::string value;

    // Find the first occurrence of " | "
    pos = line.find(" | ");
    if (pos == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return (false);
    }
    
    // Check for a second occurrence after the first one
    if (line.find(" | ", pos + 3) != std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return (false);
    }

    // If here, there is exactly one " | "
    date = line.substr(0, pos);
    value = line.substr(pos + 3);

    if (isValidDate(date) == false)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return (false);
    }

    if (isValidValue(value, parsedValue) == false)
    {
        return (false);
    }

    this->date_for_btc = date;
    this->value_for_btc = parsedValue;

    return(true);
}


bool ParseInput::isValidDate(const std::string &date)
{
    // Expected format: YYYY-MM-DD (10 chars)
    if (date.size() != 10)
        return (false);

    // Check for '-' delimiters
    if (date[4] != '-' || date[7] != '-')
        return (false);

    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
            continue ;
        else
        {
            if (isdigit(date[i]) == 0)
                return (false);
        }
    }

    // check: year >= 2009, month 1-12, day 1-31
    int y = atoi(date.substr(0, 4).c_str());
    int m = atoi(date.substr(5, 2).c_str());
    int d = atoi(date.substr(8, 2).c_str());
    if (y < 2009 || m < 1 || m > 12 || d < 1 || d > 31)
        return (false);

    return (true);
}

bool ParseInput::isValidValue(const std::string &valueStr, float &parsedValue)
{
    float tmp = 0.0f;

    std::istringstream iss(valueStr);
    iss >> tmp;

    // Check if value is not positive
    if (tmp <= 0.0f)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return (false);
    }

    // Check if value is too large
    if (tmp > 1000.0f)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return (false);
    }

    parsedValue = tmp;
    return (true);
}


const std::string &ParseInput::getDate() const
{
    return(this->date_for_btc);
}

float ParseInput::getValue() const
{
    return(this->value_for_btc);
}