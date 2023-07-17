# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 12:51:32 by cbernot           #+#    #+#              #
#    Updated: 2023/07/05 18:05:26 by cbernot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=main
SRCS=Weapon.cpp HumanA.cpp HumanB.cpp main.cpp
OBJS=$(SRCS:.cpp=.o)
INCLUDES=Weapon.hpp HumanA.hpp HumanB.hpp
CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re