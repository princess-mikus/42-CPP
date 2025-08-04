#include "Span.hpp"

int	main(void) {
	Span sp = Span(5);

	try {
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception	&e) {
		std::cerr << e.what() << std::endl;
	}
	try	{
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception	&e) {
		std::cerr << e.what() << std::endl;
	}

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try {
		sp.addNumber(18);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
	std::vector<int> vec;
	Span sp2 = Span(5);

	for (size_t i = 0; i <= 5; ++i) {
		vec.push_back(i);
	}

	sp2.addRange<std::vector<int> >(vec.begin(), vec.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}