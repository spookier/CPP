#ifndef Rpn_HPP
#define Rpn_HPP

#include <sstream>
#include <stdexcept>
#include <cctype>
#include <stack>
#include <string>
#include <iostream>


class Rpn
{
	private:
		std::stack<int>	numbers;

	public:
		Rpn();
		Rpn(const Rpn &other);
		Rpn &operator=(const Rpn &other);
		~Rpn();
		
		std::stack<int> getStack() const;

		int evaluate(const std::string &rpnArg);
};

#endif
