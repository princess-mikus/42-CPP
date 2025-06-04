#include "whatever.hpp"
#include <cstring>
#include <cstdlib>

int	main(void) {
	int	i_first = 70;
	int	i_second = 48;
	swap(i_first, i_second);

	std::cout << i_first << " vs " << i_second << std::endl;

	char	*c_str_first = new char[5];
	char	*c_str_second = new char[10];
	
	strncpy(c_str_first, "Hola", strlen("Hola"));
	strncpy(c_str_second, "Qué tal", strlen("Qué tal"));
	swap(c_str_first, c_str_second);
	
	std::cout << c_str_first << " " << c_str_second << std::endl;
	delete[] c_str_first;
	delete[] c_str_second;

	char c_first = 'c';
	char c_second = 'z';
	std::cout << min(c_first, c_second) << std::endl;

	std::string str_first = "Hola";
	std::string str_second = "Qué tal";
	std::cout << max(str_first, str_second) << std::endl;

}