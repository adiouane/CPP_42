# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 16:21:25 by adiouane          #+#    #+#              #
#    Updated: 2023/04/01 02:14:48 by adiouane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := PmergeMe

SRC := main.cpp PmergeMe.cpp

GCC := c++ -Werror -Wextra -Wall  -std=c++98 

all : $(NAME)

$(NAME) : $(SRC)
		@$(GCC) $(SRC) -o $(NAME)

clean :
	@echo "Cleaning up..."

fclean :
	@rm -f $(NAME)

re : fclean all


