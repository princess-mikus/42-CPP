#include <iostream>
#include <limits>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &model);
		ScalarConverter	&operator=(const ScalarConverter &model);
		~ScalarConverter();
		template <typename T> static void numberConvert(const T &scalar, bool nan);
	public:
		static void	convert(std::string &literal);
};
