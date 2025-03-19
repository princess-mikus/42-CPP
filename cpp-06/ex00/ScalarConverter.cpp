#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter &model) {
	(void)model;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &model) {
	(void)model;
	return *this;
}

ScalarConverter::~ScalarConverter() {

}

/*

static void	writeScalar(const int &scalar) {
	(void)scalar;
}

static void	writeScalar(const char &scalar) {
	(void)scalar;
}

static void	writeScalar(const float &scalar) {
	(void)scalar;
}

*/

static void	writeScalar(const double &scalar) {
	/* CASES FOR CHAR */
	if (scalar != scalar || scalar < 0 || scalar > 128)
		std::cout << "char: " << "impossible" << std::endl;
	else if (scalar < 32)
		std::cout << "char: " << "Non printable character" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(scalar) << std::endl;

	/* CASES FOR INT */
	if (scalar != scalar || scalar > std::numeric_limits<int>::max() || scalar < std::numeric_limits<int>::min())
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(scalar) << std::endl;

	/* CASES FOR FLOAT */
	if (scalar > std::numeric_limits<float>::max() || scalar < std::numeric_limits<float>::min())
		std::cout << "float: " <<  "impossible" << std::endl;
	else
		std::cout << "float: " <<  static_cast<float>(scalar) << "f" << std::endl;
}

void	ScalarConverter::convert(std::string &literal) {
	if (literal == "nan")
		writeScalar(std::numeric_limits<double>::quiet_NaN());
	else if (literal == "inf" || literal == "+inf")
		writeScalar(std::numeric_limits<double>::infinity());
	else if (literal == "-inf")
		writeScalar(std::numeric_limits<double>::infinity() * -1);
	else if ()
	else if (literal.find(".") == literal.npos)
		writeScalar(atoi(literal.c_str()));
	else
		writeScalar(atof(literal.c_str()));
	/*
	else if (literal.length() == 1 && !isdigit(literal[0]))
		numberConvert(literal[0], false);
	else if (literal.find('.'))
		fromFloat(atof(literal.c_str()), false);
	*/
}
/*
void	ScalarConverter::numberConvert(const int &scalar, bool nan) {
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
*/