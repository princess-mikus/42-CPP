#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed {
	public:
		/* CONSTRUCTORS AND DESTRUCTROS */
		Fixed();
		Fixed(const Fixed &to_copy);
		~Fixed();
		Fixed	&operator=(const Fixed &to_copy);

		/* SETTERS */
		void setRawBits(int const raw);

		/* GETTERS */
		int getRawBits(void) const;

	private:
		int					val = 0;
		static const int	frac = 8;
};

#endif