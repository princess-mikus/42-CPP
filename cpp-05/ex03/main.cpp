/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:21:34 by fcasaubo          #+#    #+#             */
/*   Updated: 2025/01/09 16:00:39 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

int main()
{
	Form	*newForm;
	Intern	intern;

	newForm = intern.makeForm("robotomy request", "Bender");
	delete newForm;
	newForm = intern.makeForm("road fix request", "road");
};
