#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void	swap(T &var1, T &var2) {
	if (typeid(var1) != typeid(var2))
	{
		std::cerr << "Variables not of same type" << std::endl;
		return;
	}
	T temp;
	temp = var1;
	var1 = var2;
	var2 = temp;
}

template <typename T>
T	min(T &var1, T &var2) {
	if (typeid(var1) != typeid(var2))
	{
		std::cerr << "Variables not of same type" << std::endl;
		return (0);
	}
	if (var1 < var2)
		return(var1);
	else
		return(var2);
}

template <typename T>
T	max(T &var1, T &var2) {
	if (typeid(var1) != typeid(var2))
	{
		std::cerr << "Variables not of same type" << std::endl;
		return (0);
	}
	if (var1 > var2)
		return(var1);
	else
		return(var2);
}

#endif