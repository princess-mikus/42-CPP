#include "AForm.hpp"
#include <unistd.h>
#include <random>

class PresidentialPardonForm: public AForm
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
