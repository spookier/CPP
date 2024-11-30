#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T temp = b;

	b = a;
	a = temp;
}

template <typename T>
T &min (T &n1, T &n2)
{
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}

template <typename T>
T &max (T &n1, T &n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}


#endif