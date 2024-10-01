#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string new_name);
	ClapTrap(const ClapTrap &to_copy);
	ClapTrap	&operator=(const ClapTrap &to_copy);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getName() const;
	int			getHealth() const;
	int			getEnergy() const;
	int			getAttDmg() const;
	void		setName(std::string);
	void		setHealth(int);
	void		setEnergy(int);
	void		setAttDmg(int);

private:
	std::string	name;
	int			hit_points;
	int			energy_points;
	int			attack_damage;
};

#endif