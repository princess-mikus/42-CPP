#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "Default constructor called! (Shouldn't)" << std::endl;
	name = "";
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ScavTrap::ScavTrap(std::string new_name) {
	std::cout << "Name constructor called!" << std::endl;
	name = new_name;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}