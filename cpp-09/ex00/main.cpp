#include "BitcoinExchange.hpp"

void	unix_to_time(unsigned int year, unsigned int month, unsigned int day);

int	main(void)
{
	std::tm		date;
	//unix_to_time(2015, 14, 1);
	char	*a = strptime("2014/11/1", "%Y/%m/%d", &date);
	if (!a) {
		std::cout << "A donde vas animal" << std::endl;
	}
	else {
		std::cout << asctime(&date) << std::endl;
	}
}	