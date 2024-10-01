#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	public:
		Animal();
		~Animal();
		void	makeSound();
	protected:
		std::string	type;
	private:

};

#endif