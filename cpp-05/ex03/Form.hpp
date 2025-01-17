/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:02:02 by fcasaubo          #+#    #+#             */
/*   Updated: 2025/01/09 16:43:24 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
#define Form_HPP

#include <exception>
#include <string>
#include <iostream>
#include <fstream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_execute_grade;
	public:
		Form();
		Form(std::string name, int sign_grade, int execute_grade);
		Form(const Form &model);
		Form	&operator=(const Form &model);
		~Form();

		std::string getName() const;
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;

		void		beSigned(const Bureaucrat &bureaucrat);
		void		execute(const Bureaucrat &bureaucrat);
		void		beExecuted();

		class GradeTooLowException: public std::exception
		{
			public:
				GradeTooLowException();
				const char* what() const throw();
		};
		class GradeTooHighException: public std::exception
		{
			public:
				GradeTooHighException();
				const char* what() const throw();
		};
		class FormNotSignedException: public std::exception
		{
			public:
				FormNotSignedException();
				const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &stream, const Form &model);

#endif