#include "HumanB.hpp"

HumanB::~HumanB() {
	
}

HumanB::HumanB(std::string new_name) {
	name = new_name;
}

void	HumanB::setWeapon(Weapon &new_weapon) {
	myWeapon = &new_weapon;
}

void	HumanB::attack() {
	std::cout << name << " attacks with their " << myWeapon->getType() << std::endl;
}

