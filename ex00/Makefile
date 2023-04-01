# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 19:25:53 by adiouane          #+#    #+#              #
#    Updated: 2023/03/14 19:25:53 by adiouane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := btc

SRC := main.cpp BitcoinExchange.cpp 

GCC := c++ -Werror -Wextra -Wall  -std=c++98 

all : $(NAME)

$(NAME) : $(SRC)
		@$(GCC) $(SRC) -o $(NAME)

clean :
	@echo "Cleaning up..."

fclean :
	@rm -f $(NAME)

re : fclean all
