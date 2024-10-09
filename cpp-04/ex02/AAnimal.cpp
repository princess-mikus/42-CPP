#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &to_copy) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	if (this == &to_copy)
		return ;
	type = to_copy.type;
}

AAnimal	&AAnimal::operator=(const AAnimal &to_copy) {
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this == &to_copy)
		return (*this);
	type = to_copy.type;
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string		AAnimal::getType() const {
	return (type);
}
