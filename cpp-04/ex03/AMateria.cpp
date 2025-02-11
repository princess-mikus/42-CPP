#include "AMateria.hpp"

AMateria::AMateria() {
	_type = "AMateria";
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) {
	_type = type; 
	std::cout << "AMateria name constructor called" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &to_copy) {
	std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this == &to_copy)
		return (*this);
	_type = to_copy._type;
	return (*this);
}

AMateria::AMateria(const AMateria &to_copy) {
	std::cout << "AMateria copy constructor called" << std::endl;
	if (this == &to_copy)
		return ;
	_type = to_copy._type;
}

std::string const &AMateria::getType() const {
	return (_type);
}

AMateria::~AMateria() {
	
}