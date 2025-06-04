#include "iter.hpp"

int	main(void) {
	int intArray[] = {1, 2, 3, 99, 48};
    char charArray[] = {'a', 'B', '8', 'd', 'e', '-', 21};
	
	iter(intArray, 5, getType);
	std::cout << std::endl;
	iter(charArray, 7, getType);
}