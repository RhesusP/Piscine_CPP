# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/23 18:27:15 by cbernot           #+#    #+#              #
#    Updated: 2023/07/28 15:39:13 by cbernot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=FragTrap
SRCS=main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS=$(SRCS:.cpp=.o)
INCLUDES=ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
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