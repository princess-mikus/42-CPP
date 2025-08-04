#include "easyfind.hpp"

int	main(void) {
	std::cout << "Vector: (";
	std::vector<int> vec;
	for (size_t i = 1; i <= 10; i++) {
		vec.push_back(i);
		if (i != 10)
			std::cout << i << ", ";
		else
			std::cout << i;
	}

	std::cout << ")" << std::endl;

	
	std::cout << "\t";
	easyfind(vec, 2);
	std::cout << "\t";
	easyfind(vec, 10);
	std::cout << "\t";
	easyfind(vec, 6);
	std::cout << "\t";
	easyfind(vec, 3);
	
	std::cout << "\t";
	try {
		easyfind(vec, 11);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Deque: (";

	std::deque<int>	deq;
	deq.push_back(5);
	deq.push_back(1);
	deq.push_back(9);
	deq.push_back(17);
	deq.push_back(3);
	deq.push_back(17);

	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it) {
		if (it + 1 != deq.end())
			std::cout << *it << ", ";
		else
			std::cout << *it;
	}
	
	std::cout << ")" << std::endl;

	std::cout << "\t";
	easyfind(deq, 17);
	std::cout << "\t";
	easyfind(deq, 9);
	std::cout << "\t";
	easyfind(deq, 3);
	std::cout << "\t";
	easyfind(deq, 5);
}
