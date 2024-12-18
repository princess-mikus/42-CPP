/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:09:45 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/18 19:45:06 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	try	{
		if (grade < 1)
			throw (Bureaucrat::GradeTooLowException);
		if (grade > 150)
			throw (Bureaucrat::GradeTooHighException);
	}
	catch(std::exception &e) {
		
	}
	
}

Bureaucrat::~Bureaucrat()
{
	
}


std::string	Bureaucrat::getName()
{
	return (name);
}

int	Bureaucrat::getGrade()
{
	return (grade);
}

void	Bureaucrat::promote()
{
	
}

void	Bureaucrat::demote()
{
	
}