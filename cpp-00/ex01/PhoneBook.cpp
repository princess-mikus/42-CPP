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

PhoneBook::PhoneBook() {
	stored_contacts = 0;
	last_contact = 0;
}

PhoneBook::~PhoneBook() {

}

void	PhoneBook::add_contact() {
	const std::string message[5] = {"First Name: ", "Last Name: ", "Nickname: ", "Phone Number: ", "your darkest secret: "};
	std::string	data[5];
	std::string	input;
	bool		error = false;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Insert " + message[i] + '\n';
		std::getline(std::cin, input);
		if (!input[0] || (i == 3 && !is_number(input)))
			error = true;
		if (error)
		{
			std::cerr << "Error! Not valid input" << std::endl;
			break;
		}
		data[i] = input;
	}
	if (!error)
	{
		contacts[last_contact].add_to_contact(data);
		if (last_contact < 7)
			last_contact++;
		else
			last_contact = 0;
		if (stored_contacts < 8)
			stored_contacts++;
	}
}

void	PhoneBook::search_contact() {
	std::string	index;
	std::string (Contact::*getter_list[])(void) = {&Contact::get_first_name, &Contact::get_last_name, &Contact::get_nickname};


	if (stored_contacts < 1)
	{
		std::cout << "No contacts saved!" << std::endl;
		return;
	}
	std::cout << " ___________________________________________" << std::endl;
	std::cout << "|";
	std::cout << std::setw(10) << "index";
	std::cout << "|";
	std::cout << std::setw(10) << "f. name";
	std::cout << "|";
	std::cout << std::setw(10) << "l. name";
	std::cout << "|"; 
	std::cout << std::setw(10) << "nickname";
	std::cout << "|" << std::endl;
	for (int i = 0; i < stored_contacts; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10) << std::right << i << "|";
		for (int j = 0; j < 3; j++) {
			if ((contacts[i].*getter_list[j])().length() < 10)
				std::cout << std::setw(10) << std::right << (contacts[i].*getter_list[j])() << "|";
			else
				std::cout << std::setw(10) << std::right << (contacts[i].*getter_list[j])().substr(0, 9) + "." << "|";
		}
		std::cout << std::endl;
	}
	std::cout << " ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯" << std::endl;
	std::cout << "Insert contact number" << " (0 - " << stored_contacts - 1 << ")" << std::endl;
	std::string	input;
	std::getline(std::cin, input);
	if (input.length() <= 1 && input[0] - 48 < stored_contacts && is_number(input))
		contacts[input[0] - 48].print_contact_info();
	else
		std::cout << "Not valid contact!" << std::endl;
}

bool	is_number(std::string to_check) {
	for (int i = 0; i < to_check.length(); i++)
	{
		if (to_check[i] - 48 < 0 || to_check[i] - 48 > 9)
			return (false);
	}
	return (true);
}