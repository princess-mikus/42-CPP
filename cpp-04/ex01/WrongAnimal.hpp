#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &to_copy);
		virtual ~WrongAnimal();
		WrongAnimal	&operator=(const WrongAnimal &to_copy);
		std::string		getType() const;
		void	makeSound() const;
	protected:
		std::string	type;
	private:

};

#endif