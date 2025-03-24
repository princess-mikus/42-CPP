#include <iostream>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cstring>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &model);
		ScalarConverter	&operator=(const ScalarConverter &model);
		~ScalarConverter();
	public:
		static void	convert(const std::string &literal);
};
