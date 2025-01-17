#include <iostream>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:

	public:
		Intern();
		~Intern();
		Intern(const Intern &model);
		Intern	&operator=(const Intern &model);

		Form	*makeForm(std::string formName, std::string formTarget);
};
