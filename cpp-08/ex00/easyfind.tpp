#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

template <typename T>
void	easyfind(T &haystack, int needle) {
	typename T::iterator it = find(haystack.begin(), haystack.end(), needle);
	if (it != haystack.end())
		std::cout << *it << " found at " << std::distance(haystack.begin(), it) << std::endl;
	else {
		std::stringstream	ss;
		ss << needle;
		throw std::runtime_error("Member " + ss.str() + " not found");
	}
}

#endif
