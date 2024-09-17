# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 12:54:36 by fcasaubo          #+#    #+#              #
#    Updated: 2024/09/17 13:21:12 by fcasaubo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= megaphone
CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror -std=c++98
SRC		:=	megaphone.cpp

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@echo "Clean!!!"
	@rm -rf $(NAME)

re: clean all