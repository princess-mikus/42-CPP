#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {
	public:
		/* CONSTRUCTORS AND DESTRUCTORS */
		Harl();
		~Harl();

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	complain(std::string level);
		void	filter(std::string level);
};

#endif