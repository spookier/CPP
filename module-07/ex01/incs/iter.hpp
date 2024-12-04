#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>


template <typename T, typename Func>
void iter(T *addr, size_t length, Func function)
{
	size_t i;

	i = 0;

	while(i < length)
	{
		function(addr[i]);
		i++;
	}
}

// Example functions to test

template <typename T>
void printElement(const T& element)
{
    std::cout << element << " ";
}

template <typename T>
void increment(T& element)
{
    element++;
}


#endif