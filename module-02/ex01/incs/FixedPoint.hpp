#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
	private:
		int 				fixed_point_value;
		static const int	fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& other); 
		Fixed(const int value);
		Fixed& operator=(const Fixed& other); 
		~Fixed(); // Destructor

		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif
