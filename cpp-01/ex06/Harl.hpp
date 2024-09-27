#include <string>
#include <iostream>

#ifndef HARL_HPP
#define HARL_HPP

class Harl {
	public:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	complain(std::string level);
		void	filter(std::string level);
};

#endif