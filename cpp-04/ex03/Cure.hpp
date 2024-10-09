#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure: public AMateria {
	protected:
	
	public:
		Cure();
		Cure(std::string const &type);
		std::string const &getType() const;
		Cure *clone() const;
		void use(ICharacter &target);
};

#endif