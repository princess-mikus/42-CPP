#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
	public:
		/* CONSTRUCTORS AND DESTRUCTORS */
		HumanA(std::string name, class Weapon &new_weapon);
		~HumanA();
		
		void	attack();
	private:
		std::string		name;
		class Weapon	&weapon;
};

#endif