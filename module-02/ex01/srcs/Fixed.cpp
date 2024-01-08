#include "FixedPoint.hpp"

 // const at end of functions = promises it won't modify members variables
 // when you see it = it tells you that using this function won't modify the object itself
 // example: if a function just looks at the data but doesn't change it, it should be marked as const

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

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point_value = (int)roundf(value * (1 << this->fractionalBits));
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

float	Fixed::toFloat(void) const
{
	return (((float)(this->fixed_point_value)) / (1 << this->fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->fixed_point_value >> this->fractionalBits);
}

std::ostream	&operator<<(std::ostream &ostream, Fixed const &fixed)
{
	ostream << fixed.toFloat();
	return (ostream);
}


Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
