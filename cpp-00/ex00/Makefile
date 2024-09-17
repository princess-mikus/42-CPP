# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcasaubo <fcasaubo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 12:54:36 by fcasaubo          #+#    #+#              #
#    Updated: 2024/09/17 13:27:28 by fcasaubo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= megaphone
CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror -std=c++98
SRC		:=	megaphone
CSRC	:= $(addsuffix .cpp, $(SRC))

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(CSRC) -o $(NAME)

clean:
	@echo "Clean!!!"
	@rm -rf $(NAME)

re: clean all