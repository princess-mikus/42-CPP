/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:23:48 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/09/30 13:33:17 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	std::string rogue = "Chillchuck";
	FragTrap	Mimic("Chest");

	Mimic.attack(rogue);
	Mimic.beRepaired(10);
	Mimic.takeDamage(18);
	Mimic.attack(rogue);
	Mimic.highFivesGuys();
	Mimic.takeDamage(500);
	Mimic.attack(rogue);
}