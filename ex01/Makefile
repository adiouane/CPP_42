# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 13:16:05 by adiouane          #+#    #+#              #
#    Updated: 2023/04/01 02:14:23 by adiouane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := RPN

SRC := main.cpp RPN.cpp 

GCC := c++ -Werror -Wextra -Wall  -std=c++98  -fsanitize=address

all : $(NAME)

$(NAME) : $(SRC)
		@$(GCC) $(SRC) -o $(NAME)

clean :
	@echo "Cleaning up..."

fclean :
	@rm -f $(NAME)

re : fclean all
