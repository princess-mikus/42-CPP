#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
	public:
		/* CONSTRUCTORS AND DESTRUCTORS */
		HumanB();
		HumanB(std::string name);
		~HumanB();

		/* SETTERS*/
		void	setWeapon(class Weapon &new_weapon);
		
		void	attack();
	private:
		std::string			name;
		class Weapon		*weapon = nullptr;
};

#endif
