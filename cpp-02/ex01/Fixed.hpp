#include <string>
#include <iostream>
#include <cmath>

#ifndef FIXED_HPP
#define FIXED_HPP
class Fixed {
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &to_copy);
		~Fixed();
		Fixed	&operator=(const Fixed &to_copy);
		int		toInt(void)	const;
		float	toFloat(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int					val = 0;
		static const int	frac = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif