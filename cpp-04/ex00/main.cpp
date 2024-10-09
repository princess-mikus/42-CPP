#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dogo = new Dog();
	const Animal* cato = new Cat();
	const WrongAnimal*	cursed_animal = new WrongCat();
	const WrongCat*		cursed_cato = new WrongCat();
	std::cout << dogo->getType() << " " << std::endl;
	std::cout << cato->getType() << " " << std::endl;
	cato->makeSound(); //will output the cat sound!
	dogo->makeSound();
	meta->makeSound();
	cursed_animal->makeSound();
	cursed_cato->makeSound();
	
	delete meta;
	delete dogo;
	delete cato;
	delete cursed_animal;

	return (0);
}