#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	public:
		Harl();
		void complain(std::string level_name);
		~Harl();

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif