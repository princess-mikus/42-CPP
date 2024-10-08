#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
	public:
		DiamondTrap();
		DiamondTrap(std::string new_name);
		DiamondTrap(const DiamondTrap &to_copy);
		~DiamondTrap();
		DiamondTrap	&operator=(const DiamondTrap &to_copy);
		using	ScavTrap::attack;
		void	whoAmI(void);
	private:
		std::string name;
};

#endif