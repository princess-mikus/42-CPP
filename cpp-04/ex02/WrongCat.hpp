#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat &to_copy);
		~WrongCat();
		WrongCat		&operator=(const WrongCat &to_copy);
		void	makeSound() const;
	private:

};

#endif