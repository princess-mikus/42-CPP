#include "iter.hpp"

template <typename T>
void	getType(T const &c) {
	if (isdigit(c))
		std::cout << "Digit!" << std::endl;
	else if (!isprint(c))
		std::cout << "Not printable!" << std::endl;
	else if (isupper(c))
		std::cout << "Uppercase!" << std::endl;
	else if (islower(c))
		std::cout << "Lowercase!" << std::endl;
	else
		std::cout << "Another character!" << std::endl;
}

template <typename T>
void	fibonacciTimes(T const &times) {
	for (T i = 0; i < times; i++)
	{
		
		if (i + 1 != times)
			std::cout << ", ";
	}
	std::cout << "..." << std::endl;
	
}

int	main(void) {
	int intArray[] = {1, 2, 3, 4, 22};
    char charArray[] = {'a', 'B', '8', 'd', 'e', '-', 21};
	
	iter(charArray, 7, getType);
	iter(intArray, 5, fibonacciTimes);

}