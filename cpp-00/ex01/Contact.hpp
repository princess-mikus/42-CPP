/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikus <mikus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:51:46 by mikus             #+#    #+#             */
/*   Updated: 2024/07/15 16:24:31 by mikus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contact {
	public:
   		Contact();
		void	set_contact(size_t number, std::string name, std::string surname, std::string nick, std::string darkest_sec)
		{
			phone_number	= number;
			first_name 		= name;
			last_name 		= surname;
			nickname		= nick;
			darkest_secret	= darkest_sec;
		};
		void	get_contact_info()
		{
			std::cout << "Phone number:   " << phone_number << std::endl;
			std::cout << "First Name:     " << first_name << std::endl;
			std::cout << "Last  Name:     " << last_name << std::endl;
			std::cout << "Nickname:       " << nickname << std::endl;
			std::cout << "Darkest secret: " << darkest_secret << std::endl;
		};
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
	private:	
		size_t		phone_number;
		std::string	darkest_secret;
};

Contact::Contact()
{
	
};
