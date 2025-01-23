#include "ShrubberyCreationForm.hpp"

/*--------------------------------------------------------------*/
/*				CONSTRUCTORS AND DESTRUCTORS					*/
/*--------------------------------------------------------------*/

ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationForm", 145, 137) {
	_target = "tree";

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137) {
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &model): Form("ShrubberyCreationForm", 145, 137) {
	_target = model._target;
}


ShrubberyCreationForm::~ShrubberyCreationForm() {

}

/*--------------------------------------------------------------*/
/*							GETTERS								*/
/*--------------------------------------------------------------*/

std::string	ShrubberyCreationForm::getTarget() const {
	return(_target);
}

/*--------------------------------------------------------------*/
/*						MEMBER FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	ShrubberyCreationForm::beExecuted() const {
	std::ofstream	outfile((_target + "_shrubbery").c_str());

	if (!outfile.is_open())
	{
		std::cerr << "Error: File can't be created" << std::endl;
		return ;
	}

	outfile << "									     " << std::endl;
	outfile << "               ,@@@@@@@,			     " << std::endl;
	outfile	<< "      ,,,.   ,@@@@@@/@@,  .oo8888o.      " << std::endl;
	outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o    " << std::endl;
	outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'   " << std::endl;
	outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'   " << std::endl;
	outfile << "    %&&%/ %&%%&&@@\\ V /@@' `88\v\\8 `/88'   " << std::endl;
	outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'      " << std::endl;
	outfile << "       |o|        | |         | |        " << std::endl;
	outfile << "       |.|        | |         | |        " << std::endl;
	outfile << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
	outfile << "									     " << std::endl;

	outfile.close();
}

/*--------------------------------------------------------------*/
/*						OPERATOR OVERLOADS						*/
/*--------------------------------------------------------------*/


ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &model)
{
	_target = model._target;
	return *this;
}
