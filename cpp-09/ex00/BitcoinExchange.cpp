#include "BitcoinExchange.hpp"

void	unix_to_time(unsigned int year, unsigned int month, unsigned int day) {
	std::tm		date;

	date.tm_sec = 0;
	date.tm_min = 0;
	date.tm_hour = 0;
	date.tm_wday = 0;
	date.tm_yday = 0;
	date.tm_isdst = 0;

	date.tm_mday = day;
	date.tm_mon = month - 1;
	date.tm_year = year - 1900;

	time_t utime = timegm(&date);
	std::cout << utime << std::endl;

	std::tm *date2 = gmtime(&utime);
	std::cout << asctime(date2) << std::endl;
}
