#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog: protected Animal {
	public:
		Dog();
		~Dog();
	protected:
		std::string	type;
	private:

};

#endif