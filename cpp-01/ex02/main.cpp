#include <string>
#include <iostream>

int main(void) {
	std::string brainz = "HI THIS IS BRAIN";
	std::string *stringPTR = &brainz;
	std::string &stringREF = brainz;

	std::cout << &brainz << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << brainz << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}
