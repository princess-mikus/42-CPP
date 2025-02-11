#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice: public AMateria {
	public:
		Ice();
		Ice(std::string const &type);
		Ice(const Ice &to_copy);
		Ice	&operator=(const Ice &to_copy);
		~Ice();
		std::string const &getType() const;
		Ice *clone() const;
		void use(ICharacter &target);
};

#endif