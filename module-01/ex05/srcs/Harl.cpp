#include "Harl.hpp"

Harl::Harl()
{
}

void	Harl::complain(std::string level_name)
{
	int i;
	typedef void(Harl::*func_ptr)(void);
	
	func_ptr	func[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	level_list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	i = 0;
	while (i < 4)
	{
		if (level_list[i] == level_name)
		{
			(this->*func[i])();								// (this->*func[i])() is equivalent to (this->debug)() ... etc
			break;
		}
		i++;
	}
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


Harl::~Harl()
{
}