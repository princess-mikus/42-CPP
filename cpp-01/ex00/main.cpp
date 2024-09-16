#include "Zombie.hpp"

int	main(void) {
	Zombie  *zomb = newZombie("Pedro");
	std::cout << zomb->getname() + " " << zomb->getname() + " " << zomb->getname() + " " << std::endl;
	randomChump("Oscar");
	delete zomb;
	std::cout << "Zombies should get here destroyed, as they're not needed anymore" << std::endl;
}