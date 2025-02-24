#include "whatever.hpp"

int	main(void) {
	int	i_first = 70;
	int	i_second = 48;
	swap(i_first, i_second);

	std::cout << i_first << " vs " << i_second << std::endl;

	char c_first = 'c';
	char c_second = 'z';
	std::cout << min(c_first, c_second) << std::endl;

	std::string str_first = "Hola";
	std::string str_second = "Qué tal";
	std::cout << max(str_first, str_second) << std::endl;

}