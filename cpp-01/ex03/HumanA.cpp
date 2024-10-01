#include "HumanA.hpp"

HumanA::~HumanA() {
	
}

HumanA::HumanA(std::string new_name, Weapon &new_weapon): name(new_name), weapon(new_weapon) {
}

void	HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
