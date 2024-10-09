#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Brain.hpp"
#include "AAnimal.hpp"

class Dog: public AAnimal {
	public:
		Dog();
		Dog(const Dog &to_copy);
		~Dog();
		Dog	&operator=(const Dog &to_copy);
		void	makeSound() const;
	private:
		Brain	*brain;
};

#endif