#include "Array.tpp"

int	main(void) {
	Array<int>	array(3);
	try {
		std::cout << array[0] << std::endl;
		std::cout << array[1] << std::endl;
		array[2] = 48;
		std::cout << array[2] << std::endl;
		std::cout << array[3] << std::endl;
	}
	catch	(std::out_of_range	&e) {
		std ::cout << e.what() << std::endl;
	}

	Array<char> cArray;
	cArray = array;
	std::cout << cArray[2] << std::endl;
	cArray[0] = 65;
	std::cout << array[0] << " vs " << cArray[0] << std::endl;

}