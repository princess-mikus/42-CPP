#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
	public:
		/* CONSTRUCTORS AND DESTRUCTORS */
		Zombie();
		~Zombie();
		
		/* SETTERS*/
		void		setname(std::string name);
		
		/* GETTERS */
		std::string	getname(void);
		
		void		announce(void);
	private:
		std::string	name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif