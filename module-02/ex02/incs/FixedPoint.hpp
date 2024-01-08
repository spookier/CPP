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

		bool		operator>(const Fixed& fixed) const;
		bool		operator<(const Fixed& fixed) const;
		bool		operator>=(const Fixed& fixed) const;
		bool		operator<=(const Fixed& fixed) const;
		bool		operator==(const Fixed& fixed) const;
		bool		operator!=(const Fixed& fixed) const;

		Fixed		operator+(const Fixed &fixed) const;
		Fixed		operator-(const Fixed &fixed) const;
		Fixed		operator*(const Fixed &fixed) const;
		Fixed		operator/(const Fixed &fixed) const;

		Fixed		operator++(int);	// pre increment ++i
		Fixed		&operator++(void);	// post increment i++
		Fixed		operator--(int);	// --i
		Fixed		&operator--(void);	// i--

		static			Fixed& min(Fixed &r1, Fixed &r2);
		static const	Fixed& min(const Fixed &r1, const Fixed &r2);
		static			Fixed& max(Fixed &r1, Fixed &r2);
		static const	Fixed& max(const Fixed &r1, const Fixed &r2);


};

	std::ostream&	operator<<(std::ostream &ostream, Fixed const &fixed);


#endif
