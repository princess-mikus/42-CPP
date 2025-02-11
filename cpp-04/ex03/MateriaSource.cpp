#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
		known_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &to_copy) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
		known_materia[i] = to_copy.known_materia[i]->clone();
	if (this == &to_copy)
		return ;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &to_copy) {
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this == &to_copy)
		return (*this);
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (size_t i = 0; i < 4; i++)
		if (known_materia[i])
			delete known_materia[i];
	std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* new_materia) {
	for (size_t i = 0; i < 4; i++)
	{
		if (!known_materia[i])
		{
			known_materia[i] = new_materia;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	for (size_t i = 0; i < 4; i++)
		if (known_materia[i] && known_materia[i]->getType() == type)
			return (known_materia[i]->clone());
	return (NULL);
}