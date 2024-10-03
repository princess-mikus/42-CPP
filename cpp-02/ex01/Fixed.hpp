#include <string>
#include <iostream>
#include <cmath>

#ifndef FIXED_HPP
#define FIXED_HPP
class Fixed {
	public:
		/* CONSTRUCTORS AND DESTRUCTORS */
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &to_copy);
		~Fixed();
		Fixed	&operator=(const Fixed &to_copy);

		/* SETTERS */
		void setRawBits(int const raw);

		/* GETTERS */
		int getRawBits(void) const;

		int		toInt(void)	const;
		float	toFloat(void) const;

	private:
		int					val = 0;
		static const int	frac = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif