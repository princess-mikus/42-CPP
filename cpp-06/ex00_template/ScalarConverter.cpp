#include "ScalarConverter.hpp"
#include <typeinfo>

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter &model) {
	(void)model;
}

ScalarConverter::~ScalarConverter() {

}

void	ScalarConverter::convert(std::string &literal) {
	std::cout << atoi("2167483647") << std::endl;
	if (literal == "nan")
		numberConvert(std::numeric_limits<double>::quiet_NaN(), true);
	else if (literal == "inf" || literal == "+inf")
		numberConvert(std::numeric_limits<double>::infinity(), false);
	else if (literal == "-inf")
		numberConvert(std::numeric_limits<double>::infinity() * -1, false);
	else if (literal.length() == 1 && !isdigit(literal[0]))
		numberConvert(literal[0], false);
	else if (literal.find('.'))
		numberConvert(atof(literal.c_str()), false);
	else
		numberConvert(atoi(literal.c_str()), false);
}

template <typename T>
void	ScalarConverter::numberConvert(const T &scalar, bool nan) {
	if (nan || scalar < 0 || scalar > 128)
		std::cout << "char: " << "impossible" << std::endl;
	else if (scalar < 32)
		std::cout << "char: " << "Non printable character" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(scalar) << std::endl;
	if (nan || scalar == std::numeric_limits<double>::quiet_NaN() || scalar > std::numeric_limits<int>::max() || scalar < std::numeric_limits<int>::min())
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(scalar) << std::endl;
	if (static_cast<float>(scalar) == static_cast<int>(scalar))
		std::cout << "float: " <<  static_cast<float>(scalar) << ".0f" << std::endl;
	else
		std::cout << "float: " <<  static_cast<float>(scalar) << "f" << std::endl;
	if (static_cast<double>(scalar) == static_cast<int>(scalar))
		std::cout << "double: " <<  static_cast<double>(scalar) << ".0" << std::endl;
	else
		std::cout << "double: " <<  static_cast<double>(scalar) << std::endl;
}
