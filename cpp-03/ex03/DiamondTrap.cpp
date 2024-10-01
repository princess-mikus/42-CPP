#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	setName("?");
	setHealth(100);
	setEnergy(100);
	setAttDmg(30);
}

DiamondTrap::DiamondTrap(std::string new_name) {
	std::cout << "DiamondTrap Name constructor called" << std::endl;
	setName(new_name);
	setHealth(100);
	setEnergy(100);
	setAttDmg(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap &to_copy): ScavTrap(to_copy)  {
	std::cout << "DiamondTrap Copy constructor called!" << std::endl;
	if (this == &to_copy)
		return ;
	setName(to_copy.getName());
	setHealth(to_copy.getHealth());
	setEnergy(to_copy.getEnergy());
	setAttDmg(to_copy.getAttDmg());
}

DiamondTrap::~DiamondTrap() {
	std::cout << "I'm DiamondTrap " << getName() << " and now I'm destroyed" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &to_copy) {
	std::cout << "DiamondTrap Copy assignment called!" << std::endl;
	if (this == &to_copy)
		return (*this);
	setName(to_copy.getName());
	setHealth(to_copy.getHealth());
	setEnergy(to_copy.getEnergy());
	setAttDmg(to_copy.getAttDmg());
	return (*this);
}

void	DiamondTrap::whoAmI() {
	if (getHealth() <= 0)
		std::cout << "I'm dead you moron!" << std::endl;
	else
		std::cout << "DiamondTrap " << getName() << " highfives you!" << std::endl;
}