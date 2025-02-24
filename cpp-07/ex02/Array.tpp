#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() {
	data = new T[0];
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	data = new T[n];
	_size = n;
	for (unsigned int i = 0; i < _size; i++)
		data[i] = 0;
}

template <typename T>
Array<T>::Array(const Array &model) {
	data = new T[model._size];
	_size = model._size;
	for (unsigned int i = 0; i < _size; i++)
		data[i] = model.data[i];
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &model) {
	data = new T[model._size];
	_size = model._size;
	for (unsigned int i = 0; i < _size; i++)
		data[i] = model.data[i];
	return *this;
}


template <>
Array<char>	&Array<char>::operator=(const Array<int> &model) {
	data = new char[model.size()];
	_size = model.size();
	for (unsigned int i = 0; i < _size; i++)
		data[i] = static_cast<char>(model.data[i]);
	return *this;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<char> &model) {
	data = new T[model._size];
	_size = model._size;
	for (unsigned int i = 0; i < _size; i++)
		data[i] = static_cast<int>(model.data[i]);
	return *this;
}


template <typename T>
Array<T>::~Array() {
	delete[] data;
}


template <typename T>
T	&Array<T>::operator[](unsigned int n) {
	if (n >= _size) {
		throw std::out_of_range("Exception: Position not mapped in the array!");
	}
	return (*(data + n));
}

template <typename T>
unsigned int	Array<T>::size() const {
	return (_size);
}

#endif