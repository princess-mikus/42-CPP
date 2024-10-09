#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <iostream>

class AAnimal {
	public:
		AAnimal();
		AAnimal(const AAnimal &to_copy);
		virtual ~AAnimal();
		AAnimal	&operator=(const AAnimal &to_copy);
		std::string		getType() const;
		virtual void	makeSound() const = 0;
	protected:
		std::string	type;
	private:

};

#endif