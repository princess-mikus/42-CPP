#include "Zombie.hpp"

int	main(void) {
	int	zombNum = 3;
	std::string zombName = "Pedro";
	Zombie	*Horde = zombieHorde(zombNum, zombName);
	for (int i = 0; i < zombNum; i++)
		Horde[i].announce();
	delete[] Horde;
}