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

int main(void)
{
	Bureaucrat	pedro;
	try
	{
		pedro = Bureaucrat("Pedro", 12);
		std::cout << pedro << std::endl;
		Bureaucrat juan("Juan", 158);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << pedro << std::endl;
	return (0);
}
