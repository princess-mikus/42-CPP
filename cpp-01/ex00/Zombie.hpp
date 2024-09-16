#include <iostream>
#include <string>

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

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);