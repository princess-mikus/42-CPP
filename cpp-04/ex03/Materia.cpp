#include <Materia.hpp>

Materia::Materia() {
	_type = "Materia";
	std::cout << "Materia default constructor called" << std::endl;
}

Materia::Materia(const Materia &to_copy) {
	std::cout << "Materia copy constructor called" << std::endl;
	if (this == &to_copy)
		return ;
	_type = to_copy._type;
}

Materia	&Materia::operator=(const Materia &to_copy) {
	std::cout << "Materia copy assignment operator called" << std::endl;
	if (this == &to_copy)
		return (*this);
	_type = to_copy._type;
	return (*this);
}

Materia::~Materia() {
	std::cout << "Materia destructor called" << std::endl;
}

Materia	*Materia::clone() const {
	std::cout << "Materia clone called" << std::endl;
	return (new Materia(*this));
}