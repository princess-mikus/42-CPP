#include "Brain.hpp"

Brain::Brain() {
	for (size_t i = 0; i < 100; i++)
		ideas[i] = "I don't have ideas I'm an AAnimal";
	
}

Brain::Brain(const Brain &to_copy) {
	if (this == &to_copy)
		return ;
	for (size_t i = 0; i < 100; i++)
		ideas[i] = to_copy.ideas[i];
}

Brain	&Brain::operator=(const Brain &to_copy) {
	if (this == &to_copy)
		return (*this);
	for (size_t i = 0; i < 100; i++)
		ideas[i] = to_copy.ideas[i];
	
	return (*this);
}

Brain::~Brain() {

}
