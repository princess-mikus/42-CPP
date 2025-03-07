/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:09:45 by fcasaubo          #+#    #+#             */
/*   Updated: 2025/03/07 11:53:16 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

class Form;

/*--------------------------------------------------------------*/
/*				CONSTRUCTORS AND DESTRUCTORS					*/
/*--------------------------------------------------------------*/

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(): _name("Pedro Sánchez")
{
	_grade = 69;
}

Bureaucrat::Bureaucrat(const Bureaucrat &model): _name(model._name)
{
	_grade = model._grade;
}

Bureaucrat::~Bureaucrat()
{
	
}

/*--------------------------------------------------------------*/
/*							GETTERS								*/
/*--------------------------------------------------------------*/

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

/*--------------------------------------------------------------*/
/*						MEMBER FUNCTIONS						*/
/*--------------------------------------------------------------*/

void	Bureaucrat::promote()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::demote()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(Form &form) const {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << this->getName() << " can't sign form " << form.getName(); 
		std::cout << " because it's beyond it's jurisdiction (rank difference = " << this->getGrade() - form.getSignGrade() << ")" << std::endl;
	}
}

/*--------------------------------------------------------------*/
/*						OPERATOR OVERLOADS						*/
/*--------------------------------------------------------------*/

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &model)
{
	stream << "Bureaucrat: " << model.getName() << ", grade " << model.getGrade();

	return (stream);
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &model)
{
	_grade = model._grade;
	return (*this);
}


/*--------------------------------------------------------------*/
/*							EXCEPTIONS							*/
/*--------------------------------------------------------------*/

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception on Bureaucrat grade: too low. Terminating");
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception on Bureaucrat grade: too high. Terminating");
}