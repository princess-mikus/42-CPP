#include "Array.hpp"

template <typename T>
Array<T>::Array() {
	data = new T[];
	size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	data = new T[n];
	size = n;
}

template <typename T>
Array<T>::Array(const Array &model) {
	data = model.data;
	size = model.size;
}

template <typename T>
Array<T>::~Array() {
	delete[] data;
}

template <typename T>
T	Array<T>::operator[ ](unsigned int n) {
	if (n >= size) {
		throw std::exception;
	}
	return (*(data + n));
}
