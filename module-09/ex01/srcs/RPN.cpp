#include "RPN.hpp"

int RPN::evaluate(const std::string &rpnArg)
{
	std::istringstream 	input(rpnArg);
	std::string 		token;
	int second;
	int first;
	int result = 0;

	while (input >> token)	// The extraction operator (>>) reads characters from input until it finds whitespace or EOF
	{
		// Check if token is a single-digit number
		if (token.length() == 1 && std::isdigit(token[0]))
		{
			int value = token[0] - '0';
			numbers.push(value);
		}

		// Check if token is an operator
		else if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
		{
			// Stack size must have at least two numbers to perform an operation
			if (numbers.size() < 2)
			{
				throw std::runtime_error("Error");
			}

			second = numbers.top();
			numbers.pop();

			first = numbers.top();
			numbers.pop();

			if (token[0] == '+')
				result = first + second;
			else if (token[0] == '-')
				result = first - second;
			else if (token[0] == '*')
				result = first * second;
			else if (token[0] == '/')
			{
				if (second == 0)
					throw std::runtime_error("Error. Division by zero.");
				result = first / second;
			}
			numbers.push(result);
		}
		// Any other token is invalid
		else
		{
			throw std::runtime_error("Error");
		}
	}

	// Check for exactly one result left
	if (numbers.size() != 1)
	{
		throw std::runtime_error("Error");
	}

	return numbers.top();
}
