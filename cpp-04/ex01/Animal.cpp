#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &to_copy) {
	std::cout << "Animal copy constructor called" << std::endl;
	if (this == &to_copy)
		return ;
	type = to_copy.type;
}

Animal	&Animal::operator=(const Animal &to_copy) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this == &to_copy)
		return (*this);
	type = to_copy.type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string		Animal::getType() const {
	return (type);
}

void	Animal::makeSound() const {
	std::cout << "[Insert generic animal sound]" << std::endl;
}
