#include "Harl.hpp"

Harl::Harl() {

}

Harl::~Harl() {
	
}

/* Every output here is a phrase from Sam and Max. If you haven't go and play it */

void	Harl::debug() {
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I don't know how to work it. Computers in Hell all run Linux" << std::endl;
}

void	Harl::info() {
	std::cout << "[INFO]" << std::endl;
	std::cout << "But Max, you don't even like girls!" << std::endl;
}

void	Harl::warning() {
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I saw what you did. Keep the payments coming, and nobody has to find out. ...Yeah, okay. Love you too, Mom" << std::endl;
}

void	Harl::error() {
	std::cout << "[ERROR]" << std::endl;
	std::cout << "Spontaneous combustion! What a stroke of luck!" << std::endl;
}

void	Harl::complain(std::string level) {
	void (Harl::*function_list[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	level_list[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i++) {
		if (level == level_list[i]) {
			(this->*function_list[i])();
			return;
		}
	}
	
	std::cout << "I could do this all day, and I intend to! (Level not found)" << std::endl;
}

void	Harl::filter(std::string level) {
	std::string	level_list[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;

	while (level_list[i] != level && i < 4)
		i++;

	switch (i) {
		case 0:
			complain("DEBUG");
			/* fallthrough */
		case 1:
			complain("INFO");
			/* fallthrough */
		case 2:
			complain("WARNING");
			/* fallthrough */
		case 3:
			complain("ERROR");
			break;
		default:
			complain("?");
		
	}
}