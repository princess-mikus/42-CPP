#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &to_copy) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	if (this == &to_copy)
		return ;
	type = to_copy.type;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &to_copy) {
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this == &to_copy)
		return (*this);
	type = to_copy.type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string		WrongAnimal::getType() const {
	return (type);
}

void	WrongAnimal::makeSound() const {
	std::cout << "w̴̨̨̛͉̺̖͓͚͔̠̣̙̦̬̔̇̑̅͑̏̀̓͗̍͘̚r̵͙͊̌̑͂͘͝ỏ̷̡̪͘̚n̶͕̮̹͂ģ̷̮͖̃̽̃́͗́͐͊̌̅̈́̚͝ ̷̛͎̝̄͂̈́̚̕à̶̱͙̤͎͍̤̿̊̓̃͘ǹ̵͍̤̻̹͓̳̎̌̌͘i̸̡̛̲͗m̶̨̜̰͕̬̙̟̖̪̭̈́̇̑̀̌̚͠a̴̘̮̱͓̫̍̾l̶͎̄̓̄͑́̆̈́̑͋̀̂̾́̌ ̴͍̣̰̓̆̄̐̆̈́̋̆̋̔͛́̈́̂͝n̴̢̡̡̬̭̠͔̦̠̻̟͉̑̋̈́͋̊o̷̢̲̼̲͈̯̼̅͒̾͐̍̑͌̍̅͘̚͝ḯ̴͕̩̙͚̟͎͕͍s̷̩̮̖͉̹̗̹̗̖͉̹̱̆͊͊̿̃͆͗̋͌̏̑͑̋̚ͅę̸̖̖͈͖̻͉͕͗" << std::endl;
}
