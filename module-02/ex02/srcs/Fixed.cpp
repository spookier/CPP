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

	*this = other;

	// this->fixed_point_value = other.getRawBits(); // This is the same as the line above
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
	return (ostream);					// ostream is the object that is being returned after doing the operation
}


bool	Fixed::operator>(const Fixed& fixed) const
{
	if (this->fixed_point_value > fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& fixed) const
{
	if (this->fixed_point_value < fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& fixed) const
{
	if (this->fixed_point_value >= fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& fixed) const
{
	if (this->fixed_point_value <= fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& fixed) const
{
	if (this->fixed_point_value == fixed.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& fixed) const
{
	if (this->fixed_point_value != fixed.getRawBits())
		return (true);
	return (false);
}


Fixed	Fixed::operator+(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& fixed) const
{
	if (fixed.toFloat() != 0)
		return (Fixed(this->toFloat() / fixed.toFloat()));
	std::cout << "You cannot divide by 0" << std::endl;
	return (-9999);
}

Fixed Fixed::operator++(int)
{
    Fixed fixed(*this); 			// Make a copy of the current state

    ++*this; 						// Increment the current object
    return (fixed); 					// Return the copy
}

Fixed& Fixed::operator++()\
{
    this->fixed_point_value++;	 	// Increment the current object
    return (*this);					// Return the current object
}

Fixed	Fixed::operator--(int)
{
	Fixed	fixed(*this);

	--*this;
	return (fixed);
}

Fixed&	Fixed::operator--(void)
{
	this->fixed_point_value--;
	return (*this);
}

Fixed&	Fixed::min(Fixed &r1, Fixed &r2)
{
	if (r1.getRawBits() < r2.getRawBits())
		return (r1);
	return (r2);
}

const Fixed& Fixed::min(const Fixed &r1, const Fixed &r2)
{
	if (r1.getRawBits() < r2.getRawBits())
		return (r1);
	return (r2);
}

Fixed&	Fixed::max(Fixed &r1, Fixed &r2)
{
	if (r1.getRawBits() > r2.getRawBits())
		return (r1);
	return (r2);
}

const Fixed& Fixed::max(const Fixed &r1, const Fixed &r2)
{
	if (r1.getRawBits() > r2.getRawBits())
		return (r1);
	return (r2);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
