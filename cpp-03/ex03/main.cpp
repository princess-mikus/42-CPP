/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:23:48 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/10/08 13:02:56 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void) {
	std::string rogue = "Chillchuck";
	DiamondTrap	Mimic("Chest");

	std::cout << "DiamondTrap " << Mimic.getName() << " Has " << Mimic.getHealth() << " HP" << std::endl;
	std::cout << "DiamondTrap " << Mimic.getName() << " Has " << Mimic.getEnergy() << " EP" << std::endl;
	std::cout << "DiamondTrap " << Mimic.getName() << " Has " << Mimic.getAttDmg() << " AD" << std::endl;
	Mimic.attack(rogue);
	Mimic.beRepaired(10);
	Mimic.takeDamage(18);
	Mimic.attack(rogue);
	Mimic.whoAmI();
	Mimic.takeDamage(500);
	Mimic.attack(rogue);
}