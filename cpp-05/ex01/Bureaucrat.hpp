/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:10:02 by fcasaubo          #+#    #+#             */
/*   Updated: 2025/01/09 15:55:56 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>
#include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &model);
		~Bureaucrat();
		Bureaucrat	&operator=(const Bureaucrat &model);

		std::string	getName() const;
		int			getGrade() const;
		
		void		demote();
		void		promote();

		class GradeTooLowException: public std::exception
		{
			public:
				GradeTooLowException();
				~GradeTooLowException();
				const char* what() const throw();
		};
		class GradeTooHighException: public std::exception
		{
			public:
				GradeTooHighException();
				~GradeTooHighException();
				const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &model);

#endif