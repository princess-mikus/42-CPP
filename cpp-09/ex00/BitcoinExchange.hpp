#include <iostream>
#include <map>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>

class BitcoinExchange
{
	public:
		class Date
		{
			private:
				unsigned int _year;
				unsigned int _month;
				unsigned int _day;
			public:
				Date();
				Date(unsigned int year, unsigned int month, unsigned int day);
				Date(Date &model);
				Date	&operator=(const Date &model);
				~Date();

				bool operator>(const Date &to_compare) const;
				bool operator<(const Date &to_compare) const;
				bool operator>=(const Date &to_compare) const;
				bool operator<=(const Date &to_compare) const;
				bool operator==(const Date &to_compare) const;
				bool operator!=(const Date &to_compare) const;
		};
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		~BitcoinExchange();
	private:
		std::map<Date, double> _data;
};



