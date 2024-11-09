# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmodrzej <dmodrzej@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 19:49:25 by dmodrzej          #+#    #+#              #
#    Updated: 2024/09/28 19:54:22 by dmodrzej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = megaphone

source = megaphone.cpp

all: $(name)

$(name):
	c++ -Wall -Wextra -Werror -std=c++98 $(source) -o $(name)

clean:
	rm -f $(name)

fclean: clean

re: fclean all

.PHONY: all clean fclean re