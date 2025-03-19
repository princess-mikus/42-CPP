#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(std::string filename) {
	std::ifstream	database;

	database.open(filename.c_str(), std::ios::in);
	for (std::string entry; std::getline(database, entry);)
	{
		if (!atoi(entry.c_str()))
			std::getline(database, entry);
		std::string	date_str = entry.substr(0, entry.find(','));
		size_t f_del = date_str.find('-');
		size_t s_del = date_str.find_last_of('-');

		unsigned int year = atoi(date_str.substr(0, f_del).c_str());
		unsigned int month = atoi(date_str.substr(f_del, s_del).c_str() + 1);
		unsigned int day = atoi(date_str.substr(s_del, date_str.npos).c_str() + 1);
		Date	date(year, month, day);
		double value = atof(entry.substr(date_str.size() + 1, entry.size()).c_str());
		_data.insert(std::make_pair(date, value));
	}
}

BitcoinExchange::~BitcoinExchange() {

}

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

double	BitcoinExchange::getValue(const BitcoinExchange::Date &date) {
	if (_data.find(date) != _data.end())
		return (_data.find(date)->second);
	return ((--_data.upper_bound(date))->second);
}

void	BitcoinExchange::exchange(const BitcoinExchange::Date &date, double amount) {
	std::cout << getValue(date) * amount << std::endl;
}