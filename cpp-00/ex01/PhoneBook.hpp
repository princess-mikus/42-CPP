/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:54:03 by mikus             #+#    #+#             */
/*   Updated: 2024/07/15 16:28:49 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		int		stored_contacts;
		int		last_contact;
		Contact	contacts[8];
};

PhoneBook::PhoneBook()
{
	stored_contacts = 0;
	last_contact = 0;
}
/*
PhoneBook::~PhoneBook()
{
	
};
*/