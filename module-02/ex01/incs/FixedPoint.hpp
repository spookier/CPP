#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int 				fixed_point_value;
		static const int	fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other); 

		float		toFloat(void) const;
		int			toInt(void) const;

		~Fixed();

		int getRawBits() const;
		void setRawBits(int const raw);
};

	std::ostream&	operator<<(std::ostream &ostream, Fixed const &fixed);


#endif
