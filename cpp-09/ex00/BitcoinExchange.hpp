#include <iostream>
#include <map>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange &model);
		BitcoinExchange	&operator=(const BitcoinExchange &model);
		~BitcoinExchange();
};



