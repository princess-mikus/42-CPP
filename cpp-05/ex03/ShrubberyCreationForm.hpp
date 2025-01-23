#include "Form.hpp"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


class ShrubberyCreationForm: public Form
{
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &model);
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &model);
	~ShrubberyCreationForm();

	std::string getTarget() const;

	void	beExecuted() const;
};
