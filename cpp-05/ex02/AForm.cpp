/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:02:07 by fcasaubo          #+#    #+#             */
/*   Updated: 2025/01/09 16:47:22 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*--------------------------------------------------------------*/
/*				CONSTRUCTORS AND DESTRUCTORS					*/
/*--------------------------------------------------------------*/

AForm::AForm(): _name("AForm"), _sign_grade(150), _execute_grade(1)
{
	_signed = false;
}

AForm::AForm(std::string name, int sign_grade, int execute_grade): _name(name), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
	if (sign_grade < 1)
		throw AForm::GradeTooLowException();
	if (sign_grade > 150)
		throw AForm::GradeTooHighException();
	if (execute_grade < 1)
		throw AForm::GradeTooLowException();
	if (execute_grade > 150)
		throw AForm::GradeTooHighException();
	_signed = false;
}

AForm::AForm(const AForm &model): _name(model._name), _signed(false), _sign_grade(model._sign_grade), _execute_grade(model._execute_grade)
{
	
}

AForm::~AForm()
{
	
}

/*--------------------------------------------------------------*/
/*							GETTERS								*/
/*--------------------------------------------------------------*/

std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getSigned() const
{
	return (_signed);
}

int	AForm::getSignGrade() const
{
	return (_sign_grade);
}

int	AForm::getExecuteGrade() const
{
	return (_execute_grade);
}

/*--------------------------------------------------------------*/
/*						MEMBER FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	std::cout << bureaucrat.getGrade() << this->_sign_grade << std::endl;
	if (bureaucrat.getGrade() > this->_sign_grade)
		throw GradeTooLowException();
	_signed = true;
}

void	AForm::execute(const Bureaucrat &executor) {
	if (!this->_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw GradeTooLowException();
	this->beExecuted();
}

/*--------------------------------------------------------------*/
/*						OPERATOR OVERLOADS						*/
/*--------------------------------------------------------------*/

AForm	&AForm::operator=(const AForm &model)
{
	/* This operator makes no sense */
	_signed = model._signed;
	return *this;
}

std::ostream	&operator<<(std::ostream &stream, const AForm &model)
{
	if (model.getSigned())
		stream << "AForm: " << model.getName() << " is signed ";
	else
		stream << "AForm: " << model.getName() << " is NOT signed ";
	stream << "(Needed grade " << model.getSignGrade() << " for signing and ";
	stream << "grade " << model.getExecuteGrade() << " for it to be executed)";
	return (stream);
}

/*--------------------------------------------------------------*/
/*							EXCEPTIONS							*/
/*--------------------------------------------------------------*/

AForm::GradeTooLowException::GradeTooLowException()
{
	
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Exception on Form grade: too low. Terminating");
}

AForm::GradeTooHighException::GradeTooHighException()
{
	
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Exception on Form grade: too high. Terminating");
}

AForm::FormNotSignedException::FormNotSignedException() {

}

const char* AForm::FormNotSignedException::what() const throw() {
	return("Exception on Form status: Not signed. Terminating");
}
