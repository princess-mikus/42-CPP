/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:02:07 by fcasaubo          #+#    #+#             */
/*   Updated: 2025/01/09 16:47:22 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*--------------------------------------------------------------*/
/*				CONSTRUCTORS AND DESTRUCTORS					*/
/*--------------------------------------------------------------*/

Form::Form(): _name("Form"), _sign_grade(150), _execute_grade(1)
{
	_signed = false;
}

Form::Form(std::string name, int sign_grade, int execute_grade): _name(name), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
	if (sign_grade < 1)
		throw Form::GradeTooLowException();
	if (sign_grade > 150)
		throw Form::GradeTooHighException();
	if (execute_grade < 1)
		throw Form::GradeTooLowException();
	if (execute_grade > 150)
		throw Form::GradeTooHighException();
	_signed = false;
}

Form::Form(const Form &model): _name(model._name), _signed(false), _sign_grade(model._sign_grade), _execute_grade(model._execute_grade)
{
	
}

Form	&Form::operator=(const Form &model)
{
	/* This operator makes no sense */
	_signed = model._signed;
	return *this;
}

Form::~Form()
{
	
}

/*--------------------------------------------------------------*/
/*							GETTERS								*/
/*--------------------------------------------------------------*/

std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getSigned() const
{
	return (_signed);
}

int	Form::getSignGrade() const
{
	return (_sign_grade);
}

int	Form::getExecuteGrade() const
{
	return (_execute_grade);
}

/*--------------------------------------------------------------*/
/*						MEMBER FUNCTIONS						*/
/*--------------------------------------------------------------*/

std::ostream	&operator<<(std::ostream &stream, const Form &model)
{
	if (model.getSigned())
		stream << "Form: " << model.getName() << " is signed ";
	else
		stream << "Form: " << model.getName() << " is NOT signed ";
	stream << "(Needed grade " << model.getSignGrade() << " for signing and ";
	stream << "grade " << model.getExecuteGrade() << " for it to be executed)";
	return (stream);
}

void	Form::beSigned(const Bureaucrat	&bureaucrat)
{
	std::cout << bureaucrat.getGrade() << this->_sign_grade << std::endl;
	if (bureaucrat.getGrade() > this->_sign_grade)
		throw Form::GradeTooLowException();
	_signed = true;
}

/*--------------------------------------------------------------*/
/*							EXCEPTIONS							*/
/*--------------------------------------------------------------*/

Form::GradeTooLowException::GradeTooLowException()
{
	
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Exception on Form grade: too low. Terminating");
}

Form::GradeTooHighException::GradeTooHighException()
{
	
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Exception on Form grade: too high. Terminating");
}