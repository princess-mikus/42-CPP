#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    
const Animal		*animals[100];

	Cat	cat1;
	Cat	cat2;

	for (size_t i = 0; i < 100; i++)
	{
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	for (size_t i = 0; i < 100; i++)
		std::cout << animals[i]->getType() << " " << std::endl;

	for (size_t i = 0; i < 100; i++)
		animals[i]->makeSound();

	for (size_t i = 0; i < 100; i++)
		delete animals[i];

	return 0;
}