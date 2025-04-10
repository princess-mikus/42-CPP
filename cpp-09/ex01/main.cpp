#include "RPN.hpp"

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Not enough arguments!" << std::endl;
		return (2);
	}
	try
	{
		std::cout << RPN::calculate(std::string(argv[1])) << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}