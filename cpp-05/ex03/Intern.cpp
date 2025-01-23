#include "Intern.hpp"

/*--------------------------------------------------------------*/
/*				CONSTRUCTORS AND DESTRUCTORS					*/
/*--------------------------------------------------------------*/

Intern::Intern() {

}

Intern::~Intern() {

}

Intern::Intern(const Intern &model) {
	(void)model;
}

/*--------------------------------------------------------------*/
/*						MEMBER FUNCTIONS						*/
/*--------------------------------------------------------------*/

Form	*Intern::makeForm(std::string formName, std::string formTarget) {
	std::string	form_list[] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	int	i = 0;
	Form	*retval = NULL;

	while (form_list[i] != formName && i < 4)
		i++;

	switch (i) {
		case 0:
			retval = new RobotomyRequestForm(formTarget);
			std::cout << "Intern creates " << *retval << std::endl;
			break;
			/* fallthrough */
		case 1:
			retval = new ShrubberyCreationForm(formTarget);
			std::cout << "Intern creates " << *retval << std::endl;
			break;
			/* fallthrough */
		case 2:
			retval = new RobotomyRequestForm(formTarget);
			std::cout << "Intern creates " << *retval << std::endl;
			/* fallthrough */
			break;
		default:
			std::cerr << "Form " << formName << " not found" << std::endl;
	}

	return (retval);
}

/*--------------------------------------------------------------*/
/*						OPERATOR OVERLOADS						*/
/*--------------------------------------------------------------*/

Intern	&Intern::operator=(const Intern &model) {
	(void)model;
	return *this;
}
