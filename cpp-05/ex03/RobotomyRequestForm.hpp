#include "Form.hpp"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

class RobotomyRequestForm: public Form
{
private:
	std::string _target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &model);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &model);
	~RobotomyRequestForm();

	std::string getTarget() const;

	void	beExecuted() const;
};
