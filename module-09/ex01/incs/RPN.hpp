#ifndef RPN_HPP
#define RPN_HPP

#include <sstream>
#include <stdexcept>
#include <cctype>
#include <stack>
#include <string>
#include <iostream>


class RPN
{
	private:
		std::stack<int>	numbers;

	public:
		int evaluate(const std::string &rpnArg);
};

#endif
