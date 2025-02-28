#include "easyfind.tpp"

int	main(void) {
	std::vector<int> vec = std::vector<int>({1, 2, 3});

	std::cout << easyfind(vec, 2) << std::endl;
	std::cout << easyfind(vec, 4) << std::endl;
}
