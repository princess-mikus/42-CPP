#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl	Max;

	if (argc != 2)
		return (2);
	Max.filter(argv[1]);
	return (0);
}