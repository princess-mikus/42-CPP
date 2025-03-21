#include <iostream>
#include <limits>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &model);
		ScalarConverter	&operator=(const ScalarConverter &model);
		~ScalarConverter();
	public:
		static void	convert(std::string &literal);
};
