#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	public:
		Brain();
		Brain(const Brain &to_copy);
		virtual ~Brain();
		Brain	&operator=(const Brain &to_copy);
	private:
		std::string	ideas[100];
};

#endif