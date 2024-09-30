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

int	main(void) {
	std::string rogue = "Chillchuck";
	ClapTrap	Mimic("Mimic");

	Mimic.attack(rogue);
	Mimic.beRepaired(10);
	Mimic.takeDamage(18);
	for (size_t i = 0; i < 8; i++)
		Mimic.attack(rogue);
	Mimic.beRepaired(8);
	Mimic.attack(rogue);
	Mimic.takeDamage(1);
	Mimic.takeDamage(100);
	Mimic.beRepaired(8);
	Mimic.attack(rogue);
}