#include "AForm.hpp"
#include <unistd.h>
#include <random>

class RobotomyRequestForm: public AForm
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
