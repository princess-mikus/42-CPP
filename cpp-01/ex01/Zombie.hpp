#include <iostream>
#include <string>
#include <climits>

class Zombie {
    public:
        Zombie();
        ~Zombie();
        void		announce(void);
        void		setname(std::string name);
		std::string	getname(void);
	private:
        std::string	name;
};

Zombie	*zombieHorde(int N, std::string name);