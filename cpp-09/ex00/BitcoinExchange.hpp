#include <iostream>
#include <map>
#include <ctime>

class BitcoinExchange
{
	private:
		std::map<time_t, double> data;
		BitcoinExchange(/* args */);
		~BitcoinExchange();
	public:
};