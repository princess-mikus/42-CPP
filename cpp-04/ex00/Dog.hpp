#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog: public Animal {
	public:
		Dog();
		Dog(const Dog &to_copy);
		~Dog();
		Dog	&operator=(const Dog &to_copy);
		void	makeSound() const;
	private:

};

#endif