#include "PresidentialPardonForm.hpp"

/*--------------------------------------------------------------*/
/*				CONSTRUCTORS AND DESTRUCTORS					*/
/*--------------------------------------------------------------*/

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5) {
	_target = "the soil";

}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5) {
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &model): AForm("PresidentialPardonForm", 25, 5) {
	_target = model._target;
}


PresidentialPardonForm::~PresidentialPardonForm() {

}

/*--------------------------------------------------------------*/
/*							GETTERS								*/
/*--------------------------------------------------------------*/

std::string	PresidentialPardonForm::getTarget() const {
	return(_target);
}

/*--------------------------------------------------------------*/
/*						MEMBER FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	PresidentialPardonForm::beExecuted() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

/*--------------------------------------------------------------*/
/*						OPERATOR OVERLOADS						*/
/*--------------------------------------------------------------*/


PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &model)
{
	_target = model._target;
	return *this;
}
