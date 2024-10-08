#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"


class FragTrap : virtual public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string new_name);
		FragTrap(const FragTrap &to_copy);
		~FragTrap();
		FragTrap	&operator=(const FragTrap &to_copy);
		void	highFivesGuys(void);
	private:
};

#endif