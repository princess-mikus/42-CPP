#include "Fixed.hpp"

Fixed::Fixed() {
}

Fixed::Fixed(const int num) {
	val = roundf(num * (1 << frac));
}

Fixed::Fixed(const float num) {
	val = roundf(num * (1 << frac));
}

Fixed::Fixed(const Fixed &to_copy) {
	if (this == &to_copy)
		return ;
	val = to_copy.val;
}

int		Fixed::toInt(void) const {
	return (roundf(val) / (1 << frac));
}

float	Fixed::toFloat(void) const {
	return (roundf(val) / (1 << frac));
}

Fixed	&Fixed::operator=(const Fixed &to_copy) {
	if (this != &to_copy)
		val = to_copy.val;
	return *this;
}

Fixed::~Fixed()	{
}

int	Fixed::getRawBits() const {
	return (val);
}

void	Fixed::setRawBits(int const raw) {
	val = raw;
}

std::ostream &operator<<(std::ostream &num, const Fixed &fixed_num) {
	num << fixed_num.toFloat();
	return (num);
}

bool Fixed::operator>(const Fixed &second) {
	if (this->getRawBits() > second.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &second) {
	if (this->getRawBits() < second.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &second) {
	if (this->getRawBits() >= second.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &second) {
	if (this->getRawBits() <= second.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &second) {
	if (this->getRawBits() == second.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &second) {
	if (this->getRawBits() != second.getRawBits())
		return (true);
	return (false);
}

Fixed	&Fixed::operator+(const Fixed &second) {
	this->setRawBits(this->getRawBits() + second.getRawBits());
	return (*this);
}

Fixed	&Fixed::operator-(const Fixed &second) {
	this->setRawBits(this->getRawBits() - second.getRawBits());
	return (*this);
}

Fixed	&Fixed::operator*(const Fixed &second) {
	this->setRawBits(this->getRawBits() * second.getRawBits() >> frac);
	return (*this);
}

Fixed	&Fixed::operator/(const Fixed &second) {
	this->setRawBits(this->getRawBits() / second.getRawBits() >> frac);
	return (*this);
}

Fixed	&Fixed::operator++() {
	this->val += 1;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed temp(*this);
	this->val += 1;
	return (temp);
}

Fixed	&Fixed::operator--() {
	this->val -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed temp(*this);
	this->val -= 1;
	return (temp);
}

Fixed	&Fixed::min(Fixed &n1, Fixed &n2) {
	if (n1 <= n2)
		return (n1);
	return (n2);
}

Fixed	&Fixed::min(const Fixed &n1, const Fixed &n2) {
	if (n1.getRawBits() <= n2.getRawBits())
		return ((Fixed &)n1);
	return ((Fixed &)n2);
}

Fixed	&Fixed::max(Fixed &n1, Fixed &n2) {
	if (n1 >= n2)
		return (n1);
	return (n2);
}

Fixed	&Fixed::max(const Fixed &n1, const Fixed &n2) {
	if (n1.getRawBits() >= n2.getRawBits())
		return ((Fixed &)n1);
	return ((Fixed &)n2);
}