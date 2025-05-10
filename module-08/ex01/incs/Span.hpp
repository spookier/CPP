#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

class   Span
{
	private:
		unsigned int size;
		std::vector<int> vector;

	public:
		Span(unsigned int number);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void 				addNumber(int num);
		unsigned int		shortestSpan();
		unsigned int		longestSpan();

		void fill(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		class SpanIsFullException : public std::exception
		{
			const char *what() const throw()
			{
				return ("Span is already full !");
			}
		};

		class SpanIsEmptyException : public std::exception
		{
			const char *what() const throw()
			{
				return ("Span is empty !");
			}
		};


		class SpanHasOneElementException : public std::exception
		{
			const char *what() const throw()
			{
				return ("Span has only one element !");
			}
		};
};

#endif