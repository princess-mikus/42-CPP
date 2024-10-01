#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap Default constructor called!" << std::endl;
	setName("?");
	setHealth(100);
	setEnergy(50);
	setAttDmg(20);
}

ScavTrap::ScavTrap(std::string new_name) {
	std::cout << "ScavTrap Name constructor called!" << std::endl;
	setName(new_name);
	setHealth(100);
	setEnergy(50);
	setAttDmg(20);
}

ScavTrap::ScavTrap(const ScavTrap &to_copy): ClapTrap(to_copy) {
	std::cout << "ScavTrap Copy constructor called!" << std::endl;
	if (this == &to_copy)
		return ;
	setName(to_copy.getName());
	setHealth(to_copy.getHealth());
	setEnergy(to_copy.getEnergy());
	setAttDmg(to_copy.getAttDmg());
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &to_copy) {
	std::cout << "ScavTrap Copy assignment called!" << std::endl;
	if (this == &to_copy)
		return (*this);
	setName(to_copy.getName());
	setHealth(to_copy.getHealth());
	setEnergy(to_copy.getEnergy());
	setAttDmg(to_copy.getAttDmg());
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "I'm ScavTrap " << getName() << " and now I'm destroyed" << std::endl;
}

void	ScavTrap::attack(std::string target) {
	if (getHealth() <= 0)
		std::cout << "I'm dead you moron!" << std::endl;
	else if (getEnergy() <= 0)
		std::cout << "Can't do, too tired" << std::endl;
	else
	{
		std::cout << "ScavTrap " << getName() << " attacks " << target << " causing " << getAttDmg() << " points of damage!" << std::endl;
		setEnergy(getEnergy() - 1);
	}
}

void	ScavTrap::guardGate() {
	if (getHealth() <= 0)
		std::cout << "I'm dead you moron!" << std::endl;
	else
		std::cout << "I'm " << getName() << " and now I'm guarding the gate" << std::endl;
}