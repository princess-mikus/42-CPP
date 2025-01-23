#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter &model) {
	(void)model;
}

ScalarConverter::~ScalarConverter() {

}

void	ScalarConverter::convert(std::string &literal) {
	detectType(literal);	
}

void	ScalarConverter::detectType(std::string &literal) {
	if (literal == "nan")
		numberConvert(std::numeric_limits<double>::quiet_NaN());
	else if (literal == "inf" || literal == "+inf")
		numberConvert(std::numeric_limits<double>::infinity());
	else if (literal == "-inf")
		numberConvert(std::numeric_limits<double>::infinity() * -1);
	else if (literal.length() == 1 && literal[0] >= 0 && literal[0] < 128 && !isdigit(literal[0]))
		numberConvert(literal[0]);
	else if (literal.find('.'))
		numberConvert(atof(literal.c_str()));
	else
		numberConvert(atoi(literal.c_str()));
}

template <typename T>
void	ScalarConverter::numberConvert(const T &scalar) {
	std::cout << (scalar == std::numeric_limits<double>::quiet_NaN()) << std::endl;
	if (scalar == std::numeric_limits<double>::quiet_NaN() || scalar < 0 || scalar > 128)
		std::cout << "char: " << "impossible" << std::endl;
	else if (scalar < 32)
		std::cout << "char: " << "Non printable character" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(scalar) << std::endl;
	if (scalar == std::numeric_limits<double>::quiet_NaN() || scalar > std::numeric_limits<int>::max() || scalar < std::numeric_limits<int>::min())
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
