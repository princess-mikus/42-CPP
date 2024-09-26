/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:56:27 by mikus             #+#    #+#             */
/*   Updated: 2024/07/15 16:34:11 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	line;
	
	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, line);
		if (line.compare("EXIT") == 0)
			break;
		if (line.compare("ADD") == 0)
			phonebook.add_contact();
		if (line.compare("SEARCH") == 0) 
			phonebook.search_contact();
	}
}
