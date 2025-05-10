#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename T>
typename T::const_iterator easyfind(T &container, int value)
{
	// std::find = it finds the first occurrence of the int in the container
	
    return (std::find(container.begin(), container.end(), value)); 

	//	if found  		= returns the iterator pointing to the value
	//	if not found	= returns container.end()
}

#endif
