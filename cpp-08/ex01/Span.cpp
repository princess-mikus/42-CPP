#include "Span.hpp"

Span::Span() {
	_vec.reserve(0);
}

Span::Span(unsigned int max) {
	_vec.reserve(max);
}

Span::Span(Span const &model) {
	_vec = model._vec;
}

Span	&Span::operator=(Span const &model) {
	_vec = model._vec;
	return *this;
}

Span::~Span() {
	
}

void	Span::addNumber(int n) {
	if (_vec.size() == _vec.capacity())
		throw std::out_of_range("No more capacity in the vector");
	_vec.push_back(n);
}

unsigned int	Span::shortestSpan() {
	if (_vec.size() < 2)
		throw std::length_error("Vector does not have enough elements");
	std::vector<int> tmp(_vec);
	std::sort(tmp.begin(), tmp.end());
	unsigned int	span = longestSpan();

	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1 ; it++)
	{
		if ((unsigned int)(*(it + 1) - *it) < span)
			span = (unsigned int)(*(it + 1) - *it);
	}

	return (span);
}

unsigned int	Span::longestSpan() {
	if (_vec.size() < 2)
		throw std::length_error("Vector does not have enough elements");
	std::vector<int> tmp(_vec);
	std::sort(tmp.begin(), tmp.end());
	
	return (tmp.back() - tmp.front());
}

