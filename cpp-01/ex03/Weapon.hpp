#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
	public:
		/* CONSTRUCTORS AND DESTRUCTORS */
		Weapon();
		Weapon(std::string new_type);
		~Weapon();
		
		/* SETTERS*/
		void		setType(std::string new_type);
		
		/* GETTERS */
		std::string	getType();
	private:
		std::string	type;
};

#endif