#include <string>
#include <iostream>

#ifndef FIXED_HPP
#define FIXED_HPP
class Fixed {
	public:
		Fixed();
		Fixed(const Fixed &to_copy);
		~Fixed();
		Fixed	&operator=(const Fixed &to_copy);
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int					val = 0;
		static const int	frac = 8;
};
#endif