#include "Zombie.hpp"

int	main(int argc, char **argv) {
	if (argc != 3 || atoi(argv[1]) <= 0)
		return (2);
	int	zombNum = atoi(argv[1]);
	std::string zombName = argv[2];
	Zombie	*Horde = zombieHorde(zombNum, zombName);
	for (int i = 0; i < zombNum; i++)
		Horde[i].announce();
	delete[] Horde;
}