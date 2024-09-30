#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	val = roundf(num * (1 << frac));
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	val = roundf(num * (1 << frac));
}

Fixed::Fixed(const Fixed &to_copy) {
	if (this == &to_copy)
		return ;
	std::cout << "Copy constructor called" << std::endl;
	val = to_copy.val;
}

int		Fixed::toInt(void) const {
	return (val / (1 << frac));
}

float	Fixed::toFloat(void) const {
	return (roundf(val) / (1 << frac));
}

Fixed	&Fixed::operator=(const Fixed &to_copy) {
	if (this != &to_copy)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		val = to_copy.val;
	}
	return *this;
}

Fixed::~Fixed()	{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (val);
}

void	Fixed::setRawBits(int const raw) {
	val = raw;
}

std::ostream &operator<<(std::ostream &num, const Fixed &fixed_num) {
	num << fixed_num.toFloat();
	return (num);
}