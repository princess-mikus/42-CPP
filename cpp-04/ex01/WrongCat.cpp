#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() {
	std::cout << "WrongCat default constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &to_copy): WrongAnimal(to_copy) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	if (this == &to_copy)
		return ;
	type = to_copy.type;
}

WrongCat	&WrongCat::operator=(const WrongCat &to_copy) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this == &to_copy)
		return (*this);
	type = to_copy.type;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "Ç̷̝͚͓͉͉̮͌̌͐ͅU̷̝͈͖̪̒͊R̵̼̿̒̕͝S̸̥͍̬̳̝̮̟̫̊̄̀̿̀͊̎̎́̈́͌̉E̴̢̺͔͇̦̳̦̲̝̥̮͓͂͜D̷̰̦͕̭̖͕̬̠̭̦͇̫̣͋̓̃̇̀̓͋͊́͘͜͠ ̴͖̘̩̦̬̱̻̼͇̪̏C̵̙͕̟̟̼̲͛̊͛̋̇͌͛̔̓̈́͘A̸̢̢̻͓͉̥̭̯̥͍̐̑̀͆͊̋͌́́̔͂͜͝ͅͅͅT̷͖̼̯̗͈̭̜͉͔͋́̊͌͒̑̈͐̓̕̚ ̴̢̼̠̞̲̖͕͎̬͒̈́͋̀̊͘͝ͅN̸̝͚̬̐̓̈́̈̔̈́̌̒̈́͂͝Ȏ̵̧̼͉̦͖̦͖̺͈͙̺͍͝Ī̷̛͙̘̹̺̗̬̯͚͖̮͚̒̋͊̓͛̌̕S̸̞̪͖̺̜̑͌̃͛́̈́̾̿̓̓̆̋̀̾͜Ȩ̵̭̫̟͇̯͚̭̹̝̖̞̏̊͋̋̎̉̅͋̾̋̄̎͆͘͠ͅS̸̩͔̳̦̈͗̓̆̉͆̀̋̽́̔̉̃" << std::endl;
}