#include "Zombie.hpp"

void	randomChump(std::string name) {
	Zombie	newZombie;

	newZombie.setname(name);
	newZombie.announce();
}