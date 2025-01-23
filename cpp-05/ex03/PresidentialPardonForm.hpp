#include "Form.hpp"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

class PresidentialPardonForm: public Form
{
private:
	std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &model);
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &model);
	~PresidentialPardonForm();

	std::string getTarget() const;

	void	beExecuted() const;
};
