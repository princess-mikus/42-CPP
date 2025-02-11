#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure: public AMateria {
	public:
		Cure();
		Cure(std::string const &type);
		Cure(const Cure &to_copy);
		Cure	&operator=(const Cure &to_copy);
		~Cure();
		std::string const &getType() const;
		Cure *clone() const;
		void use(ICharacter &target);
};

#endif