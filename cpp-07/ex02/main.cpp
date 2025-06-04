#include "Array.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		Array<char>	array;
		std::cout << array << std::endl;
		try {
			array[2];
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		return (0);
	}

	for (int i = 1; i < argc; i++)
	{
		Array<char> array(strlen(argv[i]));
		for (size_t j = 0; j < strlen(argv[i]); j++)
		{
			array[j] = argv[i][j];
		}
		
		std::cout << array << std::endl;

		Array<char>	array2 = array;

		std::cout << array2 << std::endl;
	}
	
	Array<int> array(5);

	srand(time(NULL));
	std::cout << "Generating: ";
	for (size_t i = 0; i < 5; i++)
	{
		int	n;
		n = rand();
		std::cout << n; 
		if (i + 1 != 5)
			std::cout << " ";
		
		array[i] = n;
	}
	std::cout << std::endl << "     Array: ";
	
	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i];

		if (i + 1 != array.size())
			std::cout << " ";
	}
	
	std::cout << std::endl;

	array[3] = 2;
	std::cout << array[3] << std::endl;

	Array<int> array2(array);
	array2[4] = 6;

	std::cout << "Array 1: ";
	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i];

		if (i + 1 != array.size())
			std::cout << " ";
	}
	std::cout << std::endl << "Array 2: ";
	for (size_t i = 0; i < array2.size(); i++)
	{
		std::cout << array2[i];

		if (i + 1 != array2.size())
			std::cout << " ";
	}
	std::cout << std::endl;

}