#include "Contact.hpp"

Contact::Contact() {

}

Contact::~Contact() {

}

void	Contact::add_to_contact(std::string *data)
{
	first_name 		= data[0];
	last_name 		= data[1];
	nickname		= data[2];
	phone_number	= data[3];
	darkest_secret	= data[4];
}

void	Contact::print_contact_info()
{
    std::cout << "Phone number:   " << phone_number << std::endl;
    std::cout << "First Name:     " << first_name << std::endl;
    std::cout << "Last  Name:     " << last_name << std::endl;
    std::cout << "Nickname:       " << nickname << std::endl;
    std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

std::string	Contact::get_first_name() {
	return (first_name);
}

std::string	Contact::get_last_name() {
	return (last_name);
}

std::string	Contact::get_nickname() {
	return (nickname);
}

std::string	Contact::get_phone_number() {
	return (phone_number);
}

std::string	Contact::get_darkest_secret() {
	return (darkest_secret);
}