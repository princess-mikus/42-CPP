#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <ICharacter.hpp>

class Character: public ICharacter {
	public:
		~Character() {}
		std::string const & getName() const;
		void equip(Materia* m);
		void unequip(int idx);
		void use(int idx, Character& target);
};

#endif