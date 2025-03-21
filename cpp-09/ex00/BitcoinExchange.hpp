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
				Date(unsigned int year = 1970, unsigned int month = 1, unsigned int day = 1);
				Date(const Date &model);
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

		double	getValue(const Date &date);
		void	exchange(const Date &date, double amount);
	private:
		std::map<Date, double> _data;
};



