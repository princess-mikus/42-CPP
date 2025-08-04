#include "BitcoinExchange.hpp"

BitcoinExchange::Date::Date(unsigned int year, unsigned int month, unsigned int day) {
	_year = year;
	if (!month || month > 12)
		throw std::out_of_range("Month not valid");
	_month = month;
	if (day > 31 || (day > 30 && (month == 4 || month == 9 || month == 11)) || (day > 29 && month == 2))
		throw std::out_of_range("Day not valid");
	if (day > 28 && month == 2 && (year % 4 || (year % 100 && !year % 400)))
		throw std::out_of_range("Not leap year");
	_day = day;
}

long	checkLValue(const std::string &str) {
	char *endptr;
	long	retval = strtol(str.c_str(), &endptr, 10);
	if (endptr == str.c_str())
		throw (std::runtime_error("Not a number"));
	if (*endptr != '\0')
		throw (std::runtime_error("Not a number"));
	return (retval);
}


BitcoinExchange::Date::Date(std::string &date, char delimiter) {
	size_t i = 0;
	
	for (size_t pos = 0; pos != date.npos;)
	{
		try {
			std::cout << date.substr(pos, date.find(pos, delimiter)) << std::endl;
			switch (i) {
				case 0:
					_year = checkLValue(date.substr(pos, date.find(pos, delimiter)));
					break;
				case 1:
					_month = checkLValue(date.substr(pos, date.find(delimiter, pos)));
					break;
				case 2:
					_day = checkLValue(date.substr(pos, date.size()));
					break;
			}
		} catch(const std::exception& e) {
			throw (std::runtime_error("Wrong Date"));
		}
		pos = date.find(delimiter) + 1;
		i++;
	}
}

BitcoinExchange::Date::Date(const BitcoinExchange::Date &model) {
	_year = model._year;
	_month = model._month;
	_day = model._day;
}

BitcoinExchange::Date	&BitcoinExchange::Date::operator=(const BitcoinExchange::Date &model) {
	_year = model._year;
	_month = model._month;
	_day = model._day;
	return *this;
}

BitcoinExchange::Date::~Date() {

}

unsigned int BitcoinExchange::Date::getYear() const {
	return (_year);
}

unsigned int BitcoinExchange::Date::getMonth() const {
	return (_month);
}

unsigned int BitcoinExchange::Date::getDay() const {
	return (_day);
}

bool	BitcoinExchange::Date::operator>(const Date &to_compare) const {
	if (_year > to_compare._year)
		return (true);
	if (_year == to_compare._year) {
		if (_month > to_compare._month)
			return (true);
		if (_month == to_compare._month) {	
			if (_day > to_compare._day)
				return (true);
		}
	}
	return (false);
}

bool	BitcoinExchange::Date::operator<(const Date &to_compare) const {
	if (_year > to_compare._year)
		return (false);
	if (_year == to_compare._year) {
		if (_month > to_compare._month)
			return (false);
		if (_month == to_compare._month) {	
			if (_day >= to_compare._day)
				return (false);
		}
	}
	return (true);
}

bool	BitcoinExchange::Date::operator>=(const Date &to_compare) const {
	if (_year > to_compare._year)
		return (true);
	if (_year == to_compare._year) {
		if (_month > to_compare._month)
			return (true);
		if (_month == to_compare._month) {	
			if (_day >= to_compare._day)
				return (true);
		}
	}
	return (false);
}

bool	BitcoinExchange::Date::operator<=(const Date &to_compare) const {
	if (_year > to_compare._year)
		return (false);
	if (_year == to_compare._year) {
		if (_month > to_compare._month)
			return (false);
		if (_month == to_compare._month) {	
			if (_day > to_compare._day)
				return (false);
		}
	}
	return (true);
}

bool	BitcoinExchange::Date::operator==(const Date &to_compare) const {
	return ((_year == to_compare._year && _month == to_compare._month && 
			_day == to_compare._day));
}

bool	BitcoinExchange::Date::operator!=(const Date &to_compare) const {
	return (!(_year == to_compare._year && _month == to_compare._month && 
			_day == to_compare._day));
}

std::ostream	&operator<<(std::ostream &stream, const BitcoinExchange::Date &model) {
	stream << model.getYear() << "/" << model.getMonth() << "/" << model.getDay();
	return (stream);
}