#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

template <typename T>
bool	easyfind(T &haystack, int needle) {

	(void)needle;	
	for(typename T::iterator	it = haystack.begin(); it != haystack.end(); it++)
	{
		if (*it == needle)
		{
			std::cout << *it << " found at " << std::distance(haystack.begin(), it) << std::endl;
			return (true);
		}
	}
	std::cerr << "Error: Not found!" << std::endl;
	return (false);
}
#endif