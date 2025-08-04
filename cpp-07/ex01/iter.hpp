#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string.h>

template <typename T>
void	iter(T *array, size_t lenght, void (*function)(T &)) {
	for (size_t i = 0; i < lenght; i++)
		function(array[i]);
}

template <typename T>
void	iter(T *array, size_t lenght, void (*function)(T const &)) {
	for (size_t i = 0; i < lenght; i++)
		function(array[i]);
}


template <typename T>
void	getType(T const &c) {
	std::cout << c << ": ";
	if (isdigit(c))
		std::cout << "Digit!" << std::endl;
	else if (!isprint(c))
		std::cout << "Not printable!" << std::endl;
	else if (isupper(c))
		std::cout << "Uppercase!" << std::endl;
	else if (islower(c))
		std::cout << "Lowercase!" << std::endl;
	else
		std::cout << "Another character!" << std::endl;
}

#endif