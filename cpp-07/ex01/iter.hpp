#include <iostream>
#include <string.h>

template <typename T>
void	iter(T *array, size_t lenght, void (*function)(T const &)) {
	for (size_t i = 0; i < lenght; i++)
	{
		function(array[i]);
	}
}