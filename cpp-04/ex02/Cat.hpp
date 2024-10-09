#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Brain.hpp"
#include "AAnimal.hpp"

class Cat: public AAnimal {
	public:
		Cat();
		Cat(const Cat &to_copy);
		~Cat();
		Cat		&operator=(const Cat &to_copy);
		void	makeSound() const;
	private:
		Brain	*brain;
};

#endif