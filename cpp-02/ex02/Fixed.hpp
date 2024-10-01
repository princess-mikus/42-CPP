#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed {
	public:
		/* CONSTRUCTORS AND DESTRUCTORS */
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &to_copy);
		~Fixed();
		Fixed	&operator=(const Fixed &to_copy);

		/* GETTERS*/
		int 	getRawBits(void) const;

		/* SETTERS*/
		void	setRawBits(int const raw);
	
		/* OPERATOR OVERLOADING */
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

		int		toInt(void)	const;
		float	toFloat(void) const;
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