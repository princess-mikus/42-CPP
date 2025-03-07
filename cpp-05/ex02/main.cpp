/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:21:34 by fcasaubo          #+#    #+#             */
/*   Updated: 2025/03/07 11:57:40 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::string 			target("test");
	Bureaucrat				pedro("Pedro Sánchez", 1);
	Bureaucrat				sebas("Sebas", 10);
	ShrubberyCreationForm	a12(target);
	RobotomyRequestForm		a22(target);
	PresidentialPardonForm	a32(target);
	std::string				reason;

	std::cout << pedro << std::endl;
	std::cout << a32 << std::endl;

	sebas.signForm(a12);
	sebas.signForm(a22);
	sebas.signForm(a32);
	pedro.executeForm(a12);
	pedro.executeForm(a22);
	pedro.executeForm(a32);

	return (0);
};
