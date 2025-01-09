/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:09:45 by fcasaubo          #+#    #+#             */
/*   Updated: 2025/01/09 16:44:03 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*--------------------------------------------------------------*/
/*				CONSTRUCTORS AND DESTRUCTORS					*/
/*--------------------------------------------------------------*/

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(): _name("Pedro Sánchez")
{
	_grade = 69;
}

Bureaucrat::~Bureaucrat()
{
	
}

Bureaucrat::Bureaucrat(const Bureaucrat &model): _name(model._name)
{
	_grade = model._grade;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &model)
{
	if (this == &model)
		return (*this);
	*this = Bureaucrat(model);
	return (*this);
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
		throw Bureaucrat::GradeTooLowException();
	_grade--;
}

void	Bureaucrat::demote()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooHighException();
	_grade++;
}

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &model)
{
	stream << "Bureaucrat: " << model.getName() << ", grade " << model.getGrade();

	return (stream);
}

/*--------------------------------------------------------------*/
/*							EXCEPTIONS							*/
/*--------------------------------------------------------------*/

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	
}

Bureaucrat::GradeTooLowException::~GradeTooLowException()
{
	
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception on Bureaucrat grade: too low. Terminating");
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	
}

Bureaucrat::GradeTooHighException::~GradeTooHighException()
{
	
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception on Bureaucrat grade: too high. Terminating");
}