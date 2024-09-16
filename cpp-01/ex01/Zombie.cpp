#include "Zombie.hpp"

Zombie::Zombie() {

}

Zombie::~Zombie() {
	std::cout << "I'm " << name << " and now I'm going the way of the Dodo!" << std::endl;
}

void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setname(std::string new_name) {	
	name = new_name;
}

std::string	Zombie::getname(void) {
	return (name);
}