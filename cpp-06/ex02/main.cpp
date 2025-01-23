#include "Functions.hpp"

int	main(void)
{
	A		*a_class = new A;
	Base	*random_class = generate();
	B		b_class;

	std::cout << "This next one is A (ptr): ";
	identify(a_class);
	std::cout << "This next one is random: ";
	identify(random_class);
	std::cout << "This next one is B (ref): ";
	identify(b_class);
	
	delete a_class;
	delete random_class;
}