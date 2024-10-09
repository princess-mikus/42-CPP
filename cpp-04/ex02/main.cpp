#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const AAnimal		*AAnimals[100];

	for (size_t i = 0; i < 100; i++)
	{
		if (i % 2)
			AAnimals[i] = new Cat();
		else
			AAnimals[i] = new Dog();
	}

	for (size_t i = 0; i < 100; i++)
		std::cout << AAnimals[i]->getType() << " " << std::endl;

	for (size_t i = 0; i < 100; i++)
		AAnimals[i]->makeSound();

	for (size_t i = 0; i < 100; i++)
		delete AAnimals[i];

	return 0;
}