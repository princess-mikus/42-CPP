#ifndef ICE_HPP
#define ICE_HPP

#include <AMateria.hpp>
#include <iostream>

class Ice: public AMateria {
	protected:
	
	public:
		Ice();
		Ice(std::string const &type);
		std::string const &getType() const;
		Ice *clone() const;
		void use(ICharacter &target);
};

#endif