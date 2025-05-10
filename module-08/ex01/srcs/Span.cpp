#include "../incs/Span.hpp"

Span::Span(unsigned int _size): size(_size)
{
}

Span::Span(const Span &other)
{
	*this = other;
}

Span& Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);

	this->size = other.size;

	return (*this);
}

Span::~Span()
{
}


void Span::addNumber(int num)
{
	if (vector.size() == this->size)
		throw (SpanIsFullException());

	vector.push_back(num);
}


unsigned int Span::shortestSpan()
{
	if (vector.size() == 0)
		throw (SpanIsEmptyException());
	if (vector.size() == 1)
		throw (SpanHasOneElementException());

	std::vector<int> temp(vector);
	std::sort(temp.begin(), temp.end()); 	// copy & sort in ascending order to not change initial vector

	int	min = temp[1] - temp[0];      		// get an initial min value


    std::vector<int>::iterator it;
	for (it = temp.begin(); it + 1 != temp.end(); ++it)
	{
		if (min > *(it + 1) - *(it)) 		// pointer arithmetic 
		{
			min = *(it + 1) - *(it);
		}
	}
	return (min);
}


unsigned int	Span::longestSpan(void)
{
	if (vector.size() == 0)
		throw (SpanIsEmptyException());
	if (vector.size() == 1)
		throw (SpanHasOneElementException());


	std::vector<int>::iterator max_iterator = std::max_element(vector.begin(), vector.end()); 	// iterator to the biggest number
	std::vector<int>::iterator min_iterator = std::min_element(vector.begin(), vector.end());	// iterator to the smallest number

	int max = *max_iterator;	// sets the int to the iterator's value by dereferencing
	int min = *min_iterator;

	return (max - min);
}


/*
	exemple how to use ::fill

	std::vector<int> source = { 5, 2, 9, 4 };
	Span sp(10);
	sp.fill(source.begin(), source.end()); <--- we pass source's begin and end iterators to ::fill
*/

void Span::fill(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int>::iterator it;

	for (it = begin; it != end; ++it)
	{
		addNumber(*it);
	}
}