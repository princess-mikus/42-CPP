#include "Weapon.hpp"

Weapon::Weapon() {
	
}

Weapon::Weapon(std::string new_type) {
	type = new_type;
}

Weapon::~Weapon() {

}

std::string	Weapon::getType() {
	return (type);
}

void Weapon::setType(std::string new_type) {
	type = new_type;
}