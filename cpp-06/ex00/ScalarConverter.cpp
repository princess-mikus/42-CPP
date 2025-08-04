#include "ScalarConverter.hpp"

static bool wrong = false;

static bool isScalar(const std::string &literal) {
	static bool e = false;

	for (size_t i = 0; literal[i]; i++)
	{
		if ((!isdigit(literal[i]) || (literal[i] == 'f' && i != literal.size())) && (literal[i] == 'e' && e) && literal[i] != '.' && literal[i] != '-' && literal[i] != '+')
			return (false);
		if (literal[i] == 'e')
			e = true;
	}
	return (true);
}

template <typename T>
static void	writeScalar(const T &scalar) {
	/* CHAR CASE */
	if (wrong || scalar != scalar || scalar < 0 || scalar > 128)
		std::cout << "char: " << "impossible" << std::endl;
	else if (scalar < 32)
		std::cout << "char: " << "Non printable character" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(scalar) << std::endl;

	/* INT CASE */
	if (wrong || scalar != scalar || scalar > std::numeric_limits<int>::max() || scalar < std::numeric_limits<int>::min())
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(scalar) << std::endl;

	/* FLOAT CASE */
	if (wrong ||
		(scalar > std::numeric_limits<float>::max() && scalar != std::numeric_limits<float>::infinity()) ||
		(scalar < -std::numeric_limits<float>::max() && scalar != -std::numeric_limits<float>::infinity()))
		std::cout << "float: " << "impossible" << std::endl;
	else if (static_cast<float>(scalar) == static_cast<int>(scalar))
		std::cout << "float: " <<  static_cast<float>(scalar) << ".0f" << std::endl;
	else
		std::cout << "float: " <<  static_cast<float>(scalar) << "f" << std::endl;

	/* DOUBLE CASE */
	if (wrong)
		std::cout << "double: " << "impossible" << std::endl;
	else if (static_cast<double>(scalar) == static_cast<int>(scalar))
		std::cout << "double: " <<  static_cast<double>(scalar) << ".0" << std::endl;
	else
		std::cout << "double: " <<  static_cast<double>(scalar) << std::endl;
}


void	ScalarConverter::convert(const std::string &literal) {
	if (literal == "nan" || literal == "nanf")
		writeScalar(std::numeric_limits<double>::quiet_NaN());
	else if (literal == "inf" || literal == "+inf")
		writeScalar(std::numeric_limits<double>::infinity());
	else if (literal == "-inf")
		writeScalar(-std::numeric_limits<double>::infinity());
	else if ((literal.length() > 1 && !isScalar(literal)))
	{
		wrong = true;
		writeScalar(0);
	}
	else if (literal.length() == 1 && !isdigit(literal[0]))
		writeScalar(literal[0]);
	else if (literal.find('.'))
		writeScalar(atof(literal.c_str()));
	else
		writeScalar(atoi(literal.c_str()));
}
