#include "../incs/Harl.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		std::cout << "Argument error" << std::endl;
		return (1);
	}

	Harl Harl;

	Harl.complain("DEBUG");
	std::cout << std::endl;

	Harl.complain("INFO");
	std::cout << std::endl;

	Harl.complain("WARNING");
	std::cout << std::endl;

	Harl.complain("ERROR");
	std::cout << std::endl;

	return (0);
}