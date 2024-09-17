/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   megaphone.cpp									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: fcasaubo <fcasaubo@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/06/12 13:32:10 by fcasaubo		  #+#	#+#			 */
/*   Updated: 2024/09/17 13:15:18 by fcasaubo		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <iostream>

std::string	str_to_mayus(char *str_org)
{
	std::string str = str_org;
	for (size_t i = 0; i < str.length(); i++)
	   str[i] = toupper(str_org[i]);
	return (str);
}


int main(int argc, char **argv) {
	std::string str;
	if (argc < 2)
		return (0);
	for (int i = 1; i < argc; i++) {
		str = str_to_mayus(argv[i]);
		std::cout << str;
		if (i != argc - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}
