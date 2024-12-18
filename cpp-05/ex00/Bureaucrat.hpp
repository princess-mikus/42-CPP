/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:10:02 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/12/18 19:47:32 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <string>

class Bureaucrat
{
	private:
		std::string const	name;
		int	grade;
		std::exception		GradeTooLowException;
		std::exception		GradeTooHighException;
	
	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		std::string	getName();
		int			getGrade();
};

