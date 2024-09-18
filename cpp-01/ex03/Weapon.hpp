#include <iostream>
#include <string>

#ifndef WEAPON_HPP
#define WEAPON_HPP

class Weapon {
	public:
		Weapon(std::string new_type);
		std::string	getType();
		void		setType(std::string new_type);
	private:
		std::string	type;
};

#endif