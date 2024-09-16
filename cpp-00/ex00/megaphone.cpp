/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:32:10 by fcasaubo          #+#    #+#             */
/*   Updated: 2024/06/12 14:03:09 by fcasaubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void    inter(char* str, int funciont(char c))
{
    for (size_t i = 0; str[i]; i++)
       str[i] = funciont(str[i]);
    
}

std::string    str_to_mayus(char *str_org)
{
    std::string str = str_org;
    for (size_t i = 0; i < str.length(); i++)
       str_org[i] = toupper(str_org[i]);
    return (str);
}


int main(int argc, char **argv) {
    (void)argc;
    std::string str;
    str = str_to_mayus(argv[1]);
    std::cout << argv[1] << '\n' << str << '\n';
    return 0;
}
