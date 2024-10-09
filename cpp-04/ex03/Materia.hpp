#ifndef MATERIA_HPP
#define MATERIA_HPP

#include <iostream>

class Materia
{
	protected:
		std::string	_type;
	public:
		Materia();
		Materia(std::string const &type);
		std::string const &getType() const; //Returns the materia type
		Materia *clone() const;
		void use(ICharacter &target);
};

#endif