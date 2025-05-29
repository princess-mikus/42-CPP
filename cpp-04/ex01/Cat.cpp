#include "Cat.hpp"

Cat::Cat(): Animal() {
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain();
	type = "Cat";
}

Cat::Cat(const Cat &to_copy): Animal(to_copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*to_copy.brain);
	if (this == &to_copy)
		return ;
	type = to_copy.type;
}

Cat	&Cat::operator=(const Cat &to_copy) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	delete brain;
	brain = new Brain(*to_copy.brain);
	if (this == &to_copy)
		return (*this);
	type = to_copy.type;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete	brain;
}

void	Cat::makeSound() const {
	std::cout << "Miau" << std::endl;
}