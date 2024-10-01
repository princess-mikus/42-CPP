#include "HumanB.hpp"

HumanB::HumanB() {
	
}

HumanB::HumanB(std::string new_name) {
	name = new_name;
}

HumanB::~HumanB() {
	
}


void	HumanB::setWeapon(Weapon &new_weapon) {
	weapon = &new_weapon;
}

void	HumanB::attack() {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

