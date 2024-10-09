#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	public:
		Animal();
		Animal(const Animal &to_copy);
		virtual ~Animal();
		Animal	&operator=(const Animal &to_copy);
		std::string		getType() const;
		virtual void	makeSound() const;
	protected:
		std::string	type;
	private:

};

#endif