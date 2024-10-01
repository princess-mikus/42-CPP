#include <string>
#include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string name, class Weapon &new_weapon);
		~HumanA();
		void	attack();
	private:
		std::string		name;
		class Weapon	&weapon;
};