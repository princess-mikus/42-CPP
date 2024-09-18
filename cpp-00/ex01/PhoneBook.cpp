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
#include <iostream>

bool	check_number(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] < '0' || input[i] > '9')
			return (true);
	}
	return (false);
}

bool	check_text(std::string input)
{

	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
			return (true);
	}
	return (false);
}

void	add_to_phonebook(PhoneBook *phonebook)
{
	const std::string message[5] = {"Phone Number: ", "First Name: ", "Last Name: ", "Nickname: ", "your darkest secret: "};
	int			number;
	std::string	data[4];
	std::string	input;
	bool		error;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Insert " + message[i] + '\n';
		std::getline(std::cin, input);
		if (!input[0])
			error = true;
		else if (i == 0)
			error = check_number(input);
		else
			error = check_text(input);
		if (error)
		{
			std::cerr << "Error! Not valid input" << std::endl;
			break;
		}
		else if (i == 0)
			number = std::atoi(input.c_str());
		else
			data[i - 1] = input;
	}
	if (!error)
	{
		if (phonebook->last_contact < 8)
		{
			phonebook->stored_contacts++;
			phonebook->last_contact++;
		}
		else
			phonebook->last_contact = 1;
		phonebook->contacts[phonebook->last_contact - 1].set_contact(\
			number, data[0], data[1], data[2], data[3]);
		std::cerr << "CONTACT ADDED" << std::endl;
	}
}

void	print_to_ten(std::string to_print)
{
	for (size_t i = 0; i < 10; i++)
	{
		if (i == 9 && i < to_print.length())
			std::cout << ".";
		else if (i < to_print.length())
			std::cout << to_print[i];
		else
			std::cout << " ";
	}
	std::cout << " | ";
}

void	search_for_contact(PhoneBook *phonebook)
{
	std::string	number;

	if (phonebook->stored_contacts == 0)
	{
		std::cout << "No contacts saved yet" << std::endl;
		return;
	}
	std::cout << " ___________________________________________________" << std::endl;
	std::cout << "| ";
	print_to_ten("  index");
	print_to_ten(" f. name");
	print_to_ten(" l. name");
	print_to_ten(" nickname");
	std::cout << std::endl;
	for (int i = 0; i < phonebook->stored_contacts; i++)
	{
		std::cout << "| ";
		print_to_ten(std::to_string(i + 1));
		print_to_ten(phonebook->contacts[i].first_name);
		print_to_ten(phonebook->contacts[i].last_name);
		print_to_ten(phonebook->contacts[i].nickname);
		std::cout << std::endl;
	}
	if (phonebook->stored_contacts != 0)
		std::cout << " ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
	std::cout << "Please insert contact number" << std::endl;
	std::getline(std::cin, number);
	if (std::atoi(number.c_str()) > 8 || std::atoi(number.c_str()) < 1)
		std::cout << "ERROR! Bad number" << std::endl;
	else if (std::atoi(number.c_str()) > phonebook->stored_contacts)
		std::cout << "Not a contact for that index!" << std::endl;
	else
		phonebook->contacts[std::atoi(number.c_str()) - 1].get_contact_info();
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	line;
	
	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, line);
		if (!line[0] || line.compare("EXIT") == 0)
			break;
		if (line.compare("ADD") == 0)
			add_to_phonebook(&phonebook);
		if (line.compare("SEARCH") == 0) 
			search_for_contact(&phonebook);
	}
}
