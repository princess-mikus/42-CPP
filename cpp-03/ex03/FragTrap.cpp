#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap Default constructor called" << std::endl;
	setName("?");
	setHealth(100);
	setEnergy(100);
	setAttDmg(30);
}

FragTrap::FragTrap(std::string new_name) {
	std::cout << "FragTrap Name constructor called" << std::endl;
	setName(new_name);
	setHealth(100);
	setEnergy(100);
	setAttDmg(30);
}

FragTrap::FragTrap(const FragTrap &to_copy): ClapTrap(to_copy)  {
	std::cout << "FragTrap Copy constructor called!" << std::endl;
	if (this == &to_copy)
		return ;
	setName(to_copy.getName());
	setHealth(to_copy.getHealth());
	setEnergy(to_copy.getEnergy());
	setAttDmg(to_copy.getAttDmg());
}

FragTrap::~FragTrap() {
	std::cout << "I'm FragTrap " << getName() << " and now I'm destroyed" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &to_copy) {
	std::cout << "FragTrap Copy assignment called!" << std::endl;
	if (this == &to_copy)
		return (*this);
	setName(to_copy.getName());
	setHealth(to_copy.getHealth());
	setEnergy(to_copy.getEnergy());
	setAttDmg(to_copy.getAttDmg());
	return (*this);
}

void	FragTrap::highFivesGuys() {
	if (getHealth() <= 0)
		std::cout << "I'm dead you moron!" << std::endl;
	else
		std::cout << "FragTrap " << getName() << " highfives you!" << std::endl;
}