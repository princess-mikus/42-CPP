#include <string>
#include <iostream>
#include <cmath>

#ifndef FIXED_HPP
#define FIXED_HPP
class Fixed {
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &to_copy);
		~Fixed();
		Fixed	&operator=(const Fixed &to_copy);
		int		toInt(void)	const;
		float	toFloat(void) const;
		int 	getRawBits(void) const;
		void	setRawBits(int const raw);
		bool	operator>(const Fixed &second);
		bool	operator<(const Fixed &second);
		bool	operator>=(const Fixed &second);
		bool	operator<=(const Fixed &second);
		bool	operator==(const Fixed &second);
		bool	operator!=(const Fixed &second);
		Fixed	&operator+(const Fixed &second);
		Fixed	&operator-(const Fixed &second);
		Fixed	&operator*(const Fixed &second);
		Fixed	&operator/(const Fixed &second);
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
		static	Fixed &min(Fixed &n1, Fixed &n2);
		static	Fixed &min(const Fixed &n1, const Fixed &n2);
		static	Fixed &max(Fixed &n1, Fixed &n2);
		static	Fixed &max(const Fixed &n1, const Fixed &n2);
	private:
		int					val = 0;
		static const int	frac = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif