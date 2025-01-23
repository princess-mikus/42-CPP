#include "RobotomyRequestForm.hpp"

/*--------------------------------------------------------------*/
/*				CONSTRUCTORS AND DESTRUCTORS					*/
/*--------------------------------------------------------------*/

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45) {
	_target = "the soil";

}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45) {
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &model): AForm("RobotomyRequestForm", 72, 45) {
	_target = model._target;
}


RobotomyRequestForm::~RobotomyRequestForm() {

}

/*--------------------------------------------------------------*/
/*							GETTERS								*/
/*--------------------------------------------------------------*/

std::string	RobotomyRequestForm::getTarget() const {
	return(_target);
}

/*--------------------------------------------------------------*/
/*						MEMBER FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	RobotomyRequestForm::beExecuted() const {
	
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << "drilling" << std::endl;
		sleep(1);
	}
	srand(time(NULL));
	int random = rand();

	if (random % 2)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << _target << " the robotomy has failed" << std::endl;
}

/*--------------------------------------------------------------*/
/*						OPERATOR OVERLOADS						*/
/*--------------------------------------------------------------*/


RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &model)
{
	_target = model._target;
	return *this;
}
