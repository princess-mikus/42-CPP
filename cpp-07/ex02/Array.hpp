#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <stdexcept>
#include <cstring>
#include <cstdlib>

template <typename T>
class Array
{
		private:
			T				*data;
			unsigned int	_size;
		public:
			Array();
			Array(unsigned int n);
			Array(const Array &model);
			Array	&operator=(const Array &model);
			~Array();
			T	&operator[ ](unsigned int n);
			T	operator[ ](unsigned int n) const;
			size_t size() const;
			T	getData(unsigned int idx) const;
};

template<typename T>
std::ostream	&operator<<(std::ostream &stream, const Array<T> &array);

#include "Array.tpp"

#endif