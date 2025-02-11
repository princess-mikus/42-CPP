#include "Character.hpp"

Character::Character() {
	std::cout << "Character default constructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
		inventory[i] = NULL;
	name = "?";
}

Character::Character(std::string new_name) {
	std::cout << "Character name constructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
		inventory[i] = NULL;
	name = new_name;
}

Character::Character(const Character &to_copy) {
	std::cout << "Character copy constructor called" << std::endl;
	if (this == &to_copy)
		return ;
	for (size_t i = 0; i < 4; i++)
		inventory[i] = to_copy.inventory[i]->clone();
	name = to_copy.name;
}

Character	&Character::operator=(const Character &to_copy) {
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this == &to_copy)
		return (*this);
	for (size_t i = 0; i < 4; i++)
		inventory[i] = to_copy.inventory[i]->clone();
	name = to_copy.name;
	return (*this);
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
		if (inventory[i])
			delete inventory[i];
}

std::string const	&Character::getName() const {
	return (name);
}

void	Character::equip(AMateria *m) {
	for (size_t i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			std::cout << m->getType() << std::endl;
			inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx) {
	inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target) {
	if (inventory[idx])
		inventory[idx]->use(target);
}