#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <Materia.hpp>

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(Materia* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
	protected:
		Materia	inventory[4];
};

#endif