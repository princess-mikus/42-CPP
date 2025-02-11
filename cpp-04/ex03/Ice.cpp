#include "Ice.hpp"

Ice::Ice(): AMateria() {
	_type = "ice";
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(std::string const &type): AMateria(type) {
	_type = type; 
	std::cout << "Ice name constructor called" << std::endl;
}

Ice::Ice(const Ice &to_copy): AMateria(to_copy) {
	std::cout << "Ice copy constructor called" << std::endl;
	if (this == &to_copy)
		return ;
	_type = to_copy._type;
}

Ice	&Ice::operator=(const Ice &to_copy) {
	std::cout << "Ice copy assignment operator called" << std::endl;
	if (this == &to_copy)
		return (*this);
	_type = to_copy._type;
	return (*this);
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

Ice	*Ice::clone() const {
	std::cout << "Ice clone called" << std::endl;
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots a bolt of ice at " << target.getName() << " *" << std::endl;
}