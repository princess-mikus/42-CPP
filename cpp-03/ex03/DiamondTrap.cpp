#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	name = "?";
	ClapTrap::setName((std::string)"?" + "_clap_name");
	setHealth(FragTrap::getHealth());
	setEnergy(ScavTrap::getEnergy());
	setAttDmg(FragTrap::getAttDmg());
}

DiamondTrap::DiamondTrap(std::string new_name) {
	ScavTrap	temp;

	std::cout << "DiamondTrap Name constructor called" << std::endl;
	name = new_name;
	ClapTrap::setName(new_name + "_clap_name");
	setHealth(FragTrap::getHealth());
	setEnergy(temp.getEnergy());
	setAttDmg(FragTrap::getAttDmg());
}

DiamondTrap::DiamondTrap(const DiamondTrap &to_copy): ClapTrap(to_copy), ScavTrap(to_copy), FragTrap(to_copy)  {
	std::cout << "DiamondTrap Copy constructor called!" << std::endl;
	if (this == &to_copy)
		return ;
	setName(to_copy.getName());
	setHealth(to_copy.getHealth());
	setEnergy(to_copy.getEnergy());
	setAttDmg(to_copy.getAttDmg());
}

DiamondTrap::~DiamondTrap() {
	std::cout << "I'm DiamondTrap " << name << " and now I'm destroyed" << std::endl;
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
		std::cout << "DiamondTrap " << name << " may or may not be " << getName() << std::endl;
}