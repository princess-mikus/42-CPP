#include "Cure.hpp"

Cure::Cure(): AMateria() {
	_type = "cure";
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(std::string const &type): AMateria(type) {
	_type = type; 
	std::cout << "Cure name constructor called" << std::endl;
}

Cure::Cure(const Cure &to_copy): AMateria(to_copy) {
	std::cout << "Cure copy constructor called" << std::endl;
	if (this == &to_copy)
		return ;
	_type = to_copy._type;
}

Cure	&Cure::operator=(const Cure &to_copy) {
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this == &to_copy)
		return (*this);
	_type = to_copy._type;
	return (*this);
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

Cure	*Cure::clone() const {
	std::cout << "Cure clone called" << std::endl;
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
