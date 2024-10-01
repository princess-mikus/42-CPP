/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:31:32 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/09/30 13:34:24 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap Default constructor called!" << std::endl;
	name = "";
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap::ClapTrap(std::string new_name) {
	std::cout << "ClapTrap Name constructor called!" << std::endl;
	name = new_name;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &to_copy) {
	if (this == &to_copy)
		return ;
	std::cout << "ClapTrap Copy constructor called!" << std::endl;
	name = to_copy.getName();
	hit_points = to_copy.getHealth();
	energy_points = to_copy.getEnergy();
	attack_damage = to_copy.getAttDmg();
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &to_copy) {
	if (this == &to_copy)
		return (*this);
	std::cout << "ClapTrap Copy assignment called!" << std::endl;
	name = to_copy.getName();
	hit_points = to_copy.getHealth();
	energy_points = to_copy.getEnergy();
	attack_damage = to_copy.getAttDmg();
	return (*this);
}

void 		ClapTrap::attack(const std::string& target) {
	if (getHealth() <= 0)
		std::cout << "I'm dead you moron!" << std::endl;
	else if (getEnergy() <= 0)
		std::cout << "Can't do, too tired" << std::endl;
	else
	{
		std::cout << "ClapTrap " << getName() << " attacks " << target << " causing " << getAttDmg() << " points of damage!" << std::endl;
		energy_points--;
	}
}

void 		ClapTrap::takeDamage(unsigned int amount) {
	if (getHealth() <= 0)
		std::cout << "I'm already dead you moron!" << std::endl;
	else
	{
		hit_points -= amount;
		if (hit_points <= 0)
		{
			std::cout << "ClapTrap " << getName() << " gets hit by " << amount << " damage and has died!" << std::endl;
			hit_points = 0;
		}
		else
			std::cout << "ClapTrap " << getName() << " gets hit by " << amount << " damage and now has " << getHealth() << " hit points!" << std::endl;
	}
}

void		ClapTrap::beRepaired(unsigned int amount) {
	if (getHealth() <= 0)
		std::cout << "I'm dead you moron!" << std::endl;
	else if (getEnergy() <= 0)
		std::cout << "Can't do, too tired" << std::endl;
	else
	{
		std::cout << "ClapTrap " << getName() << " treats its wounds, curing itself by " << amount << " hit points!" << std::endl;
		hit_points += amount;
		energy_points--;
	}
}

ClapTrap::~ClapTrap() {
	std::cout << "I'm ClapTrap " << name << " and now I'm destroyed" << std::endl;
}

std::string ClapTrap::getName() const {
	return (name);
}

int			ClapTrap::getHealth() const {
	return (hit_points);
}

int			ClapTrap::getEnergy() const {
	return (energy_points);
}

int			ClapTrap::getAttDmg() const {
	return (attack_damage);
}

void		ClapTrap::setName(std::string new_name) {
	name = new_name;
}

void		ClapTrap::setHealth(int new_hitpoints) {
	hit_points = new_hitpoints;
}

void		ClapTrap::setEnergy(int new_energypoints) {
	energy_points = new_energypoints;
}

void		ClapTrap::setAttDmg(int new_attackdamage) {
	attack_damage = new_attackdamage;
}
