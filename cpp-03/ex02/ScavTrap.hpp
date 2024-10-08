#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string new_name);
		ScavTrap(const ScavTrap &to_copy);
		~ScavTrap();
		ScavTrap	&operator=(const ScavTrap &to_copy);
		void attack(std::string);
		void guardGate();
	private:
};

#endif