#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <stdexcept>
#include <typeinfo>
#include <type_traits>

/*
template<bool b, typename T = void>
struct enable_if {
    typedef T type;
};

template<typename T>
struct enable_if<false, T> {};

template<class T, class U>
struct is_same : std::false_type {};
 
template<class T>
struct is_same<T, T> : std::true_type {};
*/
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

/*
			template <typename U>
			typename enable_if<is_same<T, int>::value && is_same<U, char>::value>::type = 0
			Array<T>	&operator=(const Array<char> &model) {
				data = new int[model._size];
				_size = model._size;
				for (unsigned int i = 0; i < _size; i++)
					data[i] = static_cast<int>(model.getData(i));
				return *this;
			}
*/
			~Array();
			T	&operator[ ](unsigned int n);
			unsigned int size() const;
			T	getData(unsigned int idx) const;
};

#endif