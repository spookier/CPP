#include "FixedPoint.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_value = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;

	// this->fixed_point_value = other.getRawBits(); // This is the same as the line above

	*this = other;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_value = value << fractionalBits;
}


Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->fixed_point_value = other.getRawBits();
	}

	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point_value = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
