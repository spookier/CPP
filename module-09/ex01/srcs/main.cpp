#include "Rpn.hpp"

int main(int argc, char **argv)
{
	int 		answer;
	std::string expression;

	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	try
	{
		Rpn rpn;
		expression = argv[1];
		answer = rpn.evaluate(expression);
		std::cout << answer << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}

	return (0);
}
