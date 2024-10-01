#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP


#include <iostream>
#include <string>
#include <climits>


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

Zombie	*zombieHorde(int N, std::string name);

#endif