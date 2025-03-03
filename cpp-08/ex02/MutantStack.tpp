#include "MutantStack.hpp"

template <typename T, typename C>
MutantStack<T, C>::MutantStack(): std::stack<T, C>() {

}

template <typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack<T, C> &model): std::stack<T, C>(model) {}

template <typename T, typename C>
MutantStack<T, C> &MutantStack<T, C>::operator=(const MutantStack<T, C> &model) {
	if (this != &model)
		this = MutantStack<T, C>(model);
	return *this;
}

template <typename T, typename C>
MutantStack<T, C>::~MutantStack() {

}

template <typename T, typename C>
typename MutantStack<T, C>::iterator	MutantStack<T, C>::begin() {
	return (this->c.begin());
}

template <typename T, typename C>
typename MutantStack<T, C>::iterator	MutantStack<T, C>::end() {
	return (this->c.end());
}

template <typename T, typename C>
typename MutantStack<T, C>::reverse_iterator		MutantStack<T, C>::rbegin() {
	return (this->c.rbegin());
}

template <typename T, typename C>
typename MutantStack<T, C>::reverse_iterator		MutantStack<T, C>::rend() {
	return (this->c.rend());
}

template <typename T, typename C>
typename MutantStack<T, C>::const_iterator			MutantStack<T, C>::begin() const {
	return (this->c.begin());
}

template <typename T, typename C>
typename MutantStack<T, C>::const_iterator			MutantStack<T, C>::end() const {
	return (this->c.end());
}

template <typename T, typename C>
typename MutantStack<T, C>::const_reverse_iterator	MutantStack<T, C>::rbegin() const {
	return (this->c.rbegin());
}

template <typename T, typename C>
typename MutantStack<T, C>::const_reverse_iterator	MutantStack<T, C>::rend() const {
	return (this->c.rend());
}