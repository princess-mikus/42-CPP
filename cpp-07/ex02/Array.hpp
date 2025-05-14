#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <stdexcept>
#include <typeinfo>
#include <type_traits>

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
			unsigned int size() const;
			T	getData(unsigned int idx) const;
};

#include "Array.tpp"

#endif