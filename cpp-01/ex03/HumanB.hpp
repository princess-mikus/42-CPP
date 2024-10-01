#include <string>
#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string name);
		~HumanB();
		void	setWeapon(class Weapon &new_weapon);
		void	attack();
	private:
		std::string			name;
		class Weapon		*weapon = nullptr;
};
